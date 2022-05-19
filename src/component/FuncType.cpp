/*******************************************
*  @file  FuncType.cpp                     *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "component/FuncType.h"
#include "exception/SemanticException.h"

using namespace ComSpen;

z3::func_decl FuncType::determine(SortList& arg_type_list,  Table* table){
    string fname = m_name;
    if (fname == "=>") {
        fname = "implies";
    }
    assert(arg_type_list.size() == m_arg_sort_list.size() - 1 ||
            m_attr == "left-assoc");
    bool is_valid = true;
    string range = m_arg_sort_list.back()->getSort();
    SortList arg_list;
    for (unsigned int i = 0; i < arg_type_list.size(); i++) {
        std::string sort;
        sort = m_arg_sort_list[(m_attr == "left-assoc" ? 0 : i)]->getSort();
        is_valid = arg_type_list[i]->getSort() == sort;
        if (!is_valid) break;
    }

    if (!is_valid) {
        throw SemanticException("the argument of " + fname + " is not matched!");
    }

    // mk
    z3::sort_vector svec(z3_ctx);
    for (auto arg : arg_type_list) {
        svec.push_back(z3_buffer.getSort(arg));
    }
    z3::sort srange = z3_buffer.getSort(range);
    return z3_ctx.function(fname.c_str(), svec, srange);
}

void FuncType::show() {
    cout << "func: " << m_name << " ";
    cout << " (";
    for (auto arg : m_arg_sort_list) {
        cout << arg->getSort() <<  " ";
    }
    cout << " <-ret) ";
    cout << "(attr: " << m_attr << ") ";
    cout << endl;
}

bool ParFuncType::isPar(std::string s) {
    for(auto st : m_par_list)
        if(st->getName() == s)
            return true;
    return false;
}

bool ParFuncType::checkEqual(
    std::string label,
    std::string type,
    std::map<std::string, std::string>& mp) {
    std::string sub_type;
    if (this->isPar(label)) {
        if(mp.find(label) == mp.end())
            mp[label] = type;
        sub_type = mp[label];
    } else sub_type = label;
    return sub_type == type;
}

z3::func_decl ParFuncType::determine(SortList& arg_type_list, Table* table) {
    string fname = m_name;
    bool is_valid = true;
    map<string, string> act_map;
    for (unsigned int i = 0; i < arg_type_list.size() && is_valid; i++) {
        if (m_arg_sort_list[i]->getArity() != 0)
            is_valid = arg_type_list[i]->getName() == m_arg_sort_list[i]->getName();
        else
            is_valid = this->checkEqual(m_arg_sort_list[i]->getSort(),
                arg_type_list[i]->getSort(), act_map);
        for(int j = 0; j < m_arg_sort_list[i]->getArity() && is_valid; j++) {
            is_valid = this->checkEqual(m_arg_sort_list[i]->getSubType(j),
                arg_type_list[i]->getSubType(j), act_map);
        }
    }
    if (!is_valid) {
        throw SemanticException("the argument of " + fname + " is not matched!");
    }

    // range may be not deteminate,
    // thus, once a new sort create 
    SortType* rst = m_arg_sort_list.back();
    SortType* range_sort =
        new SortType(z3_ctx, rst->getName(), rst->getArity());
    for(int i = 0; i < rst->getArity(); i++) {
        std::string label = m_arg_sort_list.back()->getSubType(i);
        if (this->isPar(label))
            range_sort->addSubType(act_map[label]);
        else
            range_sort->addSubType(label);
    }
    if (table->getSort(range_sort->getSort()) == nullptr)
        table->addSort(range_sort->getSort(), range_sort);
    
    z3::sort_vector svec(z3_ctx);
    for (auto arg : arg_type_list) {
        svec.push_back(z3_buffer.getSort(arg));
    }
    z3::sort srange = z3_buffer.getSort(range_sort);
    assert(srange.to_string() != "null");
    return z3_ctx.function(fname.c_str(), svec, srange);

}

void ParFuncType::show() {
    cout << " parameters <";
    for(int i = 0; i < m_par_list.size(); i++) {
        cout << m_par_list[i]->getSort();
        if (i < m_par_list.size() - 1)
            cout << ' ';
    }
    cout << "> ";
    FuncType::show();
}
