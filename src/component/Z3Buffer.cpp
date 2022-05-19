/*******************************************
*  @file  Z3Buffer.cpp                     *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "component/Z3Buffer.h"
#include "parser/Table.h"
#include <algorithm>

using namespace ComSpen;

void Z3Buffer::init(Table* table) {
    for (auto kv : table->m_sort_table) {
        z3_sort_table.insert(pair<string, z3::sort>(kv.first, kv.second->operator z3::sort()));
    }
    for (auto kv : table->m_func_table) {
        if (kv.second->isDetermine()) {
        	ostringstream oss;
            oss << kv.second->getName();
            SortList arg_list = kv.second->getArgList();
            for (auto item : arg_list)
                oss << "_" << item->getSort();
            arg_list.pop_back();
            string key = oss.str();
            z3_fun_table.insert(pair<string, z3::func_decl>
                (key, kv.second->determine(arg_list, table)));
        }
    }
    //z3_var_table.insert(pair<string, z3::expr>("emptyset", z3_ctx.constant("emptyset", z3_sort_table.at("SetInt"))));
    z3_var_table.insert(pair<string, z3::expr>("true&bool", z3_ctx.bool_val(true)));
    z3_var_table.insert(pair<string, z3::expr>("false&bool", z3_ctx.bool_val(false)));
}

void Z3Buffer::setVarEnv(Table* table) {
    for (auto v : table->m_var_stack) {
        m_var_env.push_back(getVar(v));
    }
}

z3::sort& Z3Buffer::getSort(SortType* pst) {
    string key = pst->getSort();
    if (z3_sort_table.find(key) == z3_sort_table.end()) {
        z3_sort_table.insert(pair<string, z3::sort>(key, pst->operator z3::sort()));
    }
    return z3_sort_table.at(key);
}

z3::sort Z3Buffer::getSort(string key) {
    if (z3_sort_table.find(key) == z3_sort_table.end()) {
        return z3::sort(z3_ctx);
    }
    return z3_sort_table.at(key);
}

z3::expr& Z3Buffer::getVar(Var* pvar) {
    string key = pvar->getName() + "&" + pvar->getSort()->getName();
    if (z3_var_table.find(key) == z3_var_table.end()) {
        z3_var_table.insert(pair<string, z3::expr>(key, pvar->operator z3::expr()));
    }
    return z3_var_table.at(key);
}

z3::func_decl Z3Buffer::getFuncDecl(FuncType* pft, SortList& arg_type_list, Table* table) {
    ostringstream oss;
    oss << pft->getName();
    for (auto item : arg_type_list) {
        oss << "_" << item->getName();
    }
    oss << "_" << pft->getRange();

    string key = oss.str();
    if (z3_fun_table.find(key) == z3_fun_table.end()) {
        z3_fun_table.insert(pair<string, z3::func_decl>
            (key, pft->determine(arg_type_list, table)));
    }
    return z3_fun_table.at(key);
}

z3::func_decl Z3Buffer::getFuncDecl(string key) {
    if (z3_fun_table.find(key) == z3_fun_table.end()) {
        return z3::func_decl(z3_ctx);
    }
    return z3_fun_table.at(key);
}

z3::expr Z3Buffer::getEmptyset() {
	if(z3_var_table.find("emptyset") == z3_var_table.end()){
		z3_var_table.insert(pair<string, z3::expr>("emptyset", z3_ctx.constant("emptyset", z3_sort_table.at("SetInt"))));
	}
    return z3_var_table.at("emptyset"); 
}

z3::expr Z3Buffer::getSetinterset(z3::expr& S1, z3::expr& S2) {
    z3::func_decl setinterset = z3_fun_table.at("setintersect_SetInt_SetInt_SetInt");
    z3::expr_vector args(z3_ctx);
    args.push_back(S1);
    args.push_back(S2);
    return setinterset(args);
}

z3::expr Z3Buffer::getSetunion(z3::expr& S1, z3::expr& S2) {
    z3::func_decl setunion = z3_fun_table.at("setunion_SetInt_SetInt_SetInt");
    z3::expr_vector args(z3_ctx);
    args.push_back(S1);
    args.push_back(S2);
    return setunion(args);
}

z3::expr Z3Buffer::getSet(z3::expr i) {
    z3::func_decl setd = z3_fun_table.at("set_Int_SetInt");
    z3::expr_vector args(z3_ctx);
    args.push_back(i);
    return setd(args);
}

z3::expr Z3Buffer::getSetminus(z3::expr& S1, z3::expr& S2) {
    z3::func_decl setminus = z3_fun_table.at("setminus_SetInt_SetInt_SetInt");
    z3::expr_vector args(z3_ctx);
    args.push_back(S1);
    args.push_back(S2);
    return setminus(args);
}


z3::expr Z3Buffer::getSubset(z3::expr& S1, z3::expr& S2) {
    z3::func_decl subset = z3_fun_table.at("subset_SetInt_SetInt_Bool");

    z3::expr_vector args(z3_ctx);
    args.push_back(S1);
    args.push_back(S2);
    return subset(args);
}

z3::expr Z3Buffer::getBelongsto(z3::expr& i, z3::expr& S) {
    z3::func_decl belongsto = z3_fun_table.at("belongsto_Int_SetInt_Bool");

    z3::expr_vector args(z3_ctx);
    args.push_back(i);
    args.push_back(S);
    return belongsto(args);
}

z3::expr Z3Buffer::getMax(z3::expr& S) {
    z3::func_decl max_f = z3_fun_table.at("max_SetInt_Int");

    z3::expr_vector args(z3_ctx);
    args.push_back(S);
    return max_f(args);
}

z3::expr Z3Buffer::getMin(z3::expr& S) {
    z3::func_decl min_f = z3_fun_table.at("min_SetInt_Int");

    z3::expr_vector args(z3_ctx);
    args.push_back(S);
    return min_f(args);
}

void Z3Buffer::getIntItems(z3::expr e, Z3ExprSet& items) {
    if (e.is_app()) {
        string name = e.decl().name().str();
        if (name == "min" || name == "max") {
            items.insert(e);
        } else {
            for (unsigned i=0; i<e.num_args(); i++) {
                getIntItems(e.arg(i), items);
            }
        }
    } else if (e.is_const()) {
        if (e.get_sort().to_string() == "Int") {
            items.insert(e);
        }
    }
}

void Z3Buffer::getQuantifierBounds(z3::expr exp, z3::expr_vector &bounds, z3::expr &body) {
    if (exp.is_quantifier()) {
        int bnum = Z3_get_quantifier_num_bound(Z3_context(z3_ctx), Z3_ast(exp));
        for (int i=bnum-1; i>=0; i--) {
            Z3_symbol sym = Z3_get_quantifier_bound_name(Z3_context(z3_ctx), Z3_ast(exp), i);
            Z3_sort sym_s = Z3_get_quantifier_bound_sort(Z3_context(z3_ctx), Z3_ast(exp), i);
            Z3_ast x = Z3_mk_const(Z3_context(z3_ctx), sym, sym_s);
            bounds.push_back(to_expr(z3_ctx, x));
        }
        body = exp.body().substitute(bounds);
    }
}

void Z3Buffer::show() {
    cout << "var table: \n";
    for (auto kv : z3_var_table) {
        cout << kv.first << " --> " << kv.second <<endl;
    }
    cout <<endl;
    cout << "z3::sort table: \n";
    for (auto kv : z3_sort_table) {
        cout << kv.first << " --> " << kv.second << endl;
    }
    cout <<endl;
    cout << "function table: \n";
    for (auto kv : z3_fun_table) {
        cout << kv.first << " --> " << kv.second << endl;
    }
    cout << endl;

    cout << "var env: \n";
    for (auto v : m_var_env) {
        cout << v << "  ";
    }
    cout << endl;
}


/**
 * tm1 : T1 op T2 + c1
 * tm2 : T1 op T2 + c2
 * quantelmt
 */
z3::expr Z3Buffer::getQuantElmt(z3::expr f1, z3::expr f2) {
    // cout << "f1: " << f1 <<endl;
    // cout << "f2: " << f2 <<endl;
    z3::expr_vector and_items(z3_ctx);
    for (unsigned int i=0; i<f1.num_args(); i++) {
        for (unsigned int j=0; j<f2.num_args(); j++) {
            z3::expr tm1 = f1.arg(i);
            z3::expr tm2 = f2.arg(j);
            z3::expr tm1_1 = tm1.arg(0);
            z3::expr tm1_2 = tm1.arg(1).arg(0);
            int c1 = tm1.arg(1).arg(1).get_numeral_int();
            std::string op1 = tm1.decl().name().str();
            z3::expr tm2_1 = tm2.arg(0);
            z3::expr tm2_2 = tm2.arg(1).arg(0);
            int c2 = tm2.arg(1).arg(1).get_numeral_int();
            std::string op2 = tm2.decl().name().str();

            if ((c1 & c2) == 0) continue;

            int c = std::__gcd(c1, c2);
            c =  c1 * c2 / c; //
            c1 = c / c1;
            c2 = c / c2;
            if (c != 0) {
                int case_i = 0;
                if (op1 == "<=") case_i = 0;
                else if (op1 == "=") case_i = 1;
                else if (op1 == ">=") case_i = 2;

                if (op2 == "=") case_i += 3;
                else if(op2 == ">=") case_i += 6;

                switch(case_i) {
                case 0: // <= , <=
                case 8: // >=, >=
                    break;
                case 7: // =, >=
                case 6: // <=, >=
                case 3: // <=, =
                    and_items.push_back(c1 * (tm1_1 - tm1_2) <= c2 * (tm2_1 - tm2_2));
                    break;
                case 5: // >=, =
                case 2: // >=, <=
                case 1: // =, <=
                    and_items.push_back(c2 * (tm2_1 - tm2_2) <= c1 * (tm1_1 - tm1_2));
                    break;
                case 4:
                    and_items.push_back(c1 * (tm1_1 - tm1_2) == c2 * (tm2_1 - tm2_2));
                    break;
                default:
                    std::cout << "quant_elmt :: NOT SUPPOERED!\n";
                    exit(-1);
                }
            }
        }
    }
    if (and_items.size() > 0) {
        return mk_and(and_items);
    }
    return z3_ctx.bool_val(true);
}

void Z3Buffer::getBVars(z3::expr exp, Z3ExprSet& vars_set) {
    if (exp.is_app()) {
        if (exp.is_const() && !isConstant(exp)) {
            if (exp.get_sort().to_string() == "Bool")
                vars_set.insert(exp);
        } else {
             for (unsigned int i=0; i<exp.num_args(); i++) {
                getBVars(exp.arg(i), vars_set);
            }
        }
    } else if(exp.is_quantifier()) {
        getBVars(exp.body(), vars_set);
    }
}

void Z3Buffer::getFoVars(z3::expr exp, Z3ExprSet& vars_set) {
    if (exp.is_app()) {
        if (exp.is_const() && !isConstant(exp)) {
            if (exp.get_sort().to_string() == "Int")
                vars_set.insert(exp);
        } else {
             for (unsigned int i=0; i<exp.num_args(); i++) {
                getFoVars(exp.arg(i), vars_set);
            }
        }
    } else if(exp.is_quantifier()) {
        getFoVars(exp.body(), vars_set);
    }
}

void Z3Buffer::getSoVars(z3::expr exp, Z3ExprSet& vars_set) {
    if (exp.is_app()) {
        if (exp.is_const() && !isConstant(exp)) {
            if (exp.get_sort().to_string() == "SetInt")
                if (exp.to_string() != "emptyset")
                    vars_set.insert(exp);
        } else {
             for (unsigned int i=0; i<exp.num_args(); i++) {
                getSoVars(exp.arg(i), vars_set);
            }
        }
    } else if(exp.is_quantifier()) {
        getSoVars(exp.body(), vars_set);
    }
}

void Z3Buffer::getLVars(z3::expr exp, Z3ExprSet& vars_set) {
    if (exp.is_app()) {
        if (exp.is_const() && !isConstant(exp)) {
            string s = exp.get_sort().to_string();
            if ( s != "SetInt" && s != "Int" && s != "Bool") 
                vars_set.insert(exp);
        } else {
             for (unsigned int i=0; i<exp.num_args(); i++) {
                getLVars(exp.arg(i), vars_set);
            }
        }
    } else if(exp.is_quantifier()) {
        getLVars(exp.body(), vars_set);
    }
}

bool Z3Buffer::isConstant(z3::expr exp) {
    if (exp.to_string() == "true" || exp.to_string()=="false" 
        || exp.to_string()=="emptyset" || exp.is_numeral()) return true;
    return false;
}

z3::expr Z3Buffer::mkIntVar(string prefix, int p, int a, int q) {
    prefix.append(std::to_string(p)).append("_").append(std::to_string(a)).append("_").append(std::to_string(q));
    return z3_ctx.int_const(prefix.c_str());
}

z3::expr Z3Buffer::mkIntVar(string prefix, int i) {
    prefix.append(std::to_string(i));
    return z3_ctx.int_const(prefix.c_str());
}

int Z3Buffer::indexOf(vector<z3::expr>& vec, z3::expr& e) {
    for (int i=0; i<vec.size(); i++) {
        if (vec[i].hash() == e.hash()) return i;
    }
    return -1;
}

int Z3Buffer::indexOf(vector<int>& vec, int val) {
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == val) return i;
    }
    return -1;
}

z3::expr Z3Buffer::mkEq(z3::expr v1, z3::expr v2) {
    if (v1.hash() == v2.hash()) return z3_ctx.bool_val(true);
    string s = v1.get_sort().to_string();
    if (s == "Bool" || s == "Int" || s == "SetInt") return v1 == v2;
    return z3_ctx.int_const(v1.to_string().c_str()) == z3_ctx.int_const(v2.to_string().c_str());
}


bool Z3Buffer::isFun(z3::expr e, string s) {
    return e.decl().name().str() == s;
}


bool Z3Buffer::isLocation(z3::expr e) {
    string s = e.get_sort().to_string();
    if (s == "Bool" || s == "Int" || s == "SetInt") return false;
    return true;
}


z3::expr Z3Buffer::getFirstElement(int case_i, z3::expr S) {
    if ((case_i&6) == 0) {
        return getMin(S);
    } else if((case_i&6) == 2) {
        return getMax(S);
    }
    return z3::expr(z3_ctx);
}
