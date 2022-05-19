#if !defined(Z3BUFFER_)
#define Z3BUFFER_
/*******************************************
*  @file  Z3Buffer.h                       *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-17                     *
*                                          *
*******************************************/

#include "z3++.h"
#include "SortType.h"
#include <map>

namespace ComSpen {

/**
 * the  comparator
 */
class exprcomp {
public:
        bool operator() (const z3::expr& lhs, const z3::expr& rhs) const {
                return lhs.hash() < rhs.hash();
        }
};

using Z3ExprSet = set<z3::expr, exprcomp>;
using SortList = vector<SortType*>;
class FuncType;
class Table;
class Var;

class Z3Buffer {
public:
	z3::context& z3_ctx;
    Z3Buffer(z3::context& ctx): z3_ctx(ctx) {}

    z3::sort& getSort(SortType* pst); 

    void init(Table* table);

    void setVarEnv(Table* table);
    vector<z3::expr>& getVarEnv() {return m_var_env;}

    void addVarEnv(z3::expr var) {m_var_env.push_back(var);}

    z3::expr& getVar(Var* pvar);

    z3::func_decl getFuncDecl(FuncType* pft, SortList& arg_type_list,  Table* table);
    z3::func_decl getFuncDecl(string key);
    z3::sort getSort(string key);

    z3::expr getEmptyset();
    z3::expr getSetinterset(z3::expr& S1, z3::expr& S2);
    z3::expr getSetunion(z3::expr& S1, z3::expr& S2);
    z3::expr getSet(z3::expr i);
    z3::expr getSetminus(z3::expr& S1, z3::expr& S2);
    z3::expr getSubset(z3::expr& S1, z3::expr& S2);
    z3::expr getBelongsto(z3::expr& i, z3::expr& S);
    z3::expr getMax(z3::expr& S);
    z3::expr getMin(z3::expr& S);

    void getQuantifierBounds(z3::expr e, z3::expr_vector& bounds, z3::expr& body);

    void getIntItems(z3::expr e, Z3ExprSet& items);

    z3::expr getQuantElmt(z3::expr tm1, z3::expr tm2);

    void getBVars(z3::expr e, Z3ExprSet& vars_set);
    void getFoVars(z3::expr e, Z3ExprSet& vars_set);
    void getSoVars(z3::expr e, Z3ExprSet& vars_set);
    void getLVars(z3::expr e, Z3ExprSet& vars_set);

    bool isConstant(z3::expr e);

    int indexOf(vector<z3::expr>& vec, z3::expr& e);
    int indexOf(vector<int>& vec, int i);

    z3::expr mkEq(z3::expr v1, z3::expr v2);
    bool isFun(z3::expr e, string s);
    bool isLocation(z3::expr e);

    z3::expr getFirstElement(int case_i, z3::expr S);

    z3::expr mkIntVar(string prefix, int p, int a, int q);
    z3::expr mkIntVar(string prefix, int i);

    void show();

protected:
    map<string, z3::sort> z3_sort_table;
    map<string, z3::expr> z3_var_table;
    map<string, z3::func_decl> z3_fun_table; 

    vector<z3::expr> m_var_env;
};

}

#endif
