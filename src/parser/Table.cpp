/*******************************************
*  @file  Table.cpp                       * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "parser/Table.h"
#include "Types.h"
#include "parser/CommandParserFactory.h"
//#include "component/Z3Buffer.h"


extern SyntaxErrorTable SYNTAX_ERROR_INFO;
//extern Z3Buffer z3_buffer;
//extern z3::context z3_ctx;

/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @return Return parameter description
 */

Table::Table(z3::context& ctx, Z3Buffer& buffer) 
: z3_ctx(ctx), z3_buffer(buffer), m_problem(ctx) { 
    addVarScope();
    theories.push_back("Core");
}

void Table::addField(std::string name, Field* field, int row, int col) {
    if (m_field_table.find(name) != m_field_table.end()) {
        throw SemanticException("Redefined sort!", row, col); 
    }
    m_field_table[name] = field;
}

void Table::addSort(string name, SortType* st, int row, int col) {
    if (m_sort_table.find(name) != m_sort_table.end()) {
        throw SemanticException("Redefined sort!", row, col); 
    }
    m_sort_table[name] = st;
}

void Table::addFunc(string name, FuncType* ft, int row, int col) {
    if (m_func_table.find(name) != m_func_table.end()) {
        throw SemanticException("Redefined function!", row, col); 
    }
    m_func_table[name] = ft;
}

Field* Table::getField(std::string& name) {
    if (m_field_table.find(name) != m_field_table.end())
        return m_field_table[name];
    return nullptr;
}

FuncType* Table::getFunc(string& name) {
    if (m_func_table.find(name) != m_func_table.end())
        return m_func_table[name];
    return nullptr;
}

SortType* Table::getSort(string& name) {
    if (m_sort_table.find(name) != m_sort_table.end())
        return m_sort_table[name];
    return nullptr;
}


void Table::popVar() {
    int start = m_scope_mark_stack.back();
    m_scope_mark_stack.pop_back();
    for (auto pv=m_var_stack.begin()+start; pv != m_var_stack.end(); pv++) {
        delete (*pv);
    }
    m_var_stack.erase(m_var_stack.begin()+start, m_var_stack.end());
}

void Table::topVar(VarList& vlist) {
    int start = m_scope_mark_stack.back();
    for (auto pv=m_var_stack.begin()+start; pv != m_var_stack.end(); pv++) {
       vlist.push_back(*pv); 
    }
}

void Table::showEnv() {
    cout << "supported fileds: ";
    for(auto p : m_field_table) {
        cout << "(" << p.first << ", ";
        cout << p.second->getSort() << ") ";
    }
    cout << endl;
    cout << endl;
    cout << "var environment: \n";
    int i = 0;
    for (auto item: m_var_stack) {
        cout << i++ << ": ";
        item->show();
        cout << endl;
    }
    cout << "var scope: \n";
    for (auto item : m_scope_mark_stack) {
        cout << item << " ";
    }
    cout << endl;
    cout << endl;
}

void Table::show() {
    cout << "supported sort: ";
    for (auto item : m_sort_table) {
        cout << item.first << " ";
    }
    cout << endl;
    cout << "supported func: \n";
    for (auto item: m_func_table) {
        item.second->show();
        cout << endl;
    }
    cout << endl;

    showEnv();
}

Table::~Table() {
    for (auto item : m_sort_table) {
        delete item.second;
    }
    for (auto item : m_func_table) {
        delete item.second;
    }
}
