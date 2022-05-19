#if !defined(SEPSOLVER_)
#define SEPSOLVER_
/*******************************************
*  @file  SepSolver.h                      *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "component/Problem.h"
#include "Predicate_SLID_SET.h"
#include "Graph.h"
#include "component/Z3Buffer.h"

namespace ComSpen {

using EdgeType = pair<pair<int, int>, int>;
using RelationMatrix = vector<vector<int>>;

class SepSolver {
public:
	z3::context& z3_ctx;
	Z3Buffer& z3_buffer;
    SepSolver(z3::context& ctx, Z3Buffer& buffer);
    virtual ~SepSolver(); 
    void setProblem(Problem* problem); 

    void solve();

    string checkSat();
    string checkEntl();
    string check(z3::expr& phi, z3::expr_vector& free_items);
    
    z3::expr getAbsPhi(z3::expr_vector& free_items);
    z3::expr getAbsPsi(z3::expr_vector& free_items);

    void initRm();
    void computeEqClass();

    void constructPhiGraph(Graph& g);
    void constructPsiGraph(Graph& g);

    bool checkAllocatingPlans(Graph& g_phi, Graph& g_psi);
    bool matchGraph(Graph& omega, Graph& g_psi);
    bool matchPto(z3::expr& psi_atom, z3::expr& omega_atom);
    bool _matchPredicate(z3::expr& psi_atom, vector<int>& path);
    bool matchPredicate(z3::expr& psi_atom, vector<int>& path);
    
    void showEqClass();
    void showRM();
    void printPhi(Graph& g_phi, string fname);
    
protected:
	z3::expr getSpatialAbs(z3::expr& atom, int i, z3::expr_vector& new_bools, z3::expr_vector& free_items);
    z3::expr getSpatialStar(z3::expr_vector& new_bools);
    z3::expr getAbs(z3::expr_vector& free_items, z3::expr& phi);

    void _constructPhiGraph(Graph& g, RelationMatrix& rm);
    void _computeEqClass(RelationMatrix& rm, vector<int>& loc_eq, vector<set<int>>& eq_class);
    void atomToEdge(z3::expr& atom, EdgeType& edge, vector<z3::expr>& locations);

    void initInfo(z3::expr& phi, vector<z3::expr>& locations, RelationMatrix& rm);
    void initRm(z3::expr& abs, vector<z3::expr>& locations, RelationMatrix& rm, z3::expr_vector& free_items);
    void initPhiAllocated();

    void getOmegaAbs(z3::expr& omega_abs_i, Graph& omega_g_i, vector<int>& omega, z3::expr& omega_abs_i1); // next omega
    bool nextOmega(vector<int>& curr, vector<int>& target);

    bool checkPsiPredEmpty(z3::expr& psi_pred);
    
private:
    int getSuffixIdx(string& str);

protected:
    Problem* m_problem;
    
    z3::expr m_abs_phi;
    z3::expr_vector m_phi_free_items;
    z3::expr m_abs_psi;
    z3::expr_vector m_psi_free_items;

    vector<z3::expr> m_phi_location;
    vector<int> m_phi_location_eq_class;
    vector<set<int>> m_phi_eq_class;
    RelationMatrix m_phi_location_relation;
    vector<int> m_phi_space_allocated;

    vector<z3::expr> m_psi_location;
    vector<int> m_psi_location_eq_class;
    vector<set<int>> m_psi_eq_class;
    RelationMatrix m_psi_location_relation;
    
    z3::expr_vector m_new_vars;
    
    int m_counter;
};

}

#endif
