#if !defined(TABLE_)
#define TABLE_
/*******************************************
*  @file  Table.h                         * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include <iostream>
#include "z3++.h"
#include "Types.h"
#include "scanner/Scanner.h"
#include "scanner/TokenScannerFactory.h"
#include "exception/SemanticException.h"
#include "exception/SyntaxException.h"
#include "component/Field.h"
#include "component/FuncType.h"
#include "component/SortType.h"
#include "component/Var.h"
#include "component/Problem.h"

#include "solvers/slah/HeapChunk.h"

namespace ComSpen {

using FieldTable = std::map<std::string, Field*>;
using SortTable = map<string, SortType*>; 
using FuncTable = map<string, FuncType*>;
using VarStack = vector<Var*>;
using ScopeMarkStack = vector<int>;
using OpStack = vector<string>;
using ArgStack = vector<z3::expr>;
using ArgScopeStack = vector<int>; 

using VarList = vector<Var*>;

class Z3Buffer;

/*! @class Table
 *  @brief Brief class description
 *
 *  Detailed description
 */
class Table
{
public:
	z3::context& z3_ctx;
	Z3Buffer& z3_buffer;
    Table(z3::context& ctx, Z3Buffer& buffer);
    virtual ~Table();

    void addSort(string name, SortType* st, int row=-1, int col=-1); 
    void addFunc(string name, FuncType* ft, int row=-1, int col=-1); 

    SortType* getSort(string name);
    FuncType* getFunc(string name);

    void addVar(Var* pvar);
    void addVarScope();
    Var* getVar(string& name);
    void popVar();
    void topVar(VarList& vlist);

    // fill problem
    void addPredicate(Predicate* pred) {m_problem->setPredicate(pred);} 
    void addHeapChunk(HeapChunk* hck) {m_problem->setHeapChunk(hck);} 
    void addPhi(z3::expr& phi) {m_problem->setPhi(phi);}
    void addPsi(z3::expr& psi) {m_problem->setPsi(psi);}
    
    void setProblem(Problem* problem) { m_problem = problem; }
    Problem* getProblem() {return m_problem;}

    void mkApp();

    void show();

    void showEnv();

    void showProblem() {m_problem->show();}

    void addLogic(string logic) { this->logic = logic; m_problem->setLogic(logic); }
    void addLogicInfo(string key, string value) { logic_info[key] = value; }
    void addTheory(string theory) { theories.push_back(theory); }
    void addTheoryInfo(string key, string value) { theory_info[key] = value; }
    
    string getLogic() { return logic; }
    const vector<std::string>& getTheories() { return theories; }

    void addField(std::string name, Field* field, int row=-1, int col=-1);
    Field* getField(std::string name);

    bool isFixedOp(std::string op);

private:
    friend class Z3Buffer;
    
    std::string logic;
    vector<std::string> theories;
    std::map<std::string, std::string> logic_info;
    std::map<std::string, std::string> theory_info;

    FieldTable m_field_table;
    SortTable m_sort_table; ///< global sort table
    FuncTable m_func_table; ///< global function table

    VarStack m_var_stack; ///< var environment
    ScopeMarkStack m_scope_mark_stack; ///< scope mark

    Problem* m_problem; ///< problem description
};

}

#endif
