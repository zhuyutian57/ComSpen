#if !defined(PROBLEM_)
#define PROBLEM_
/*******************************************
*  @file  Problem.h                        *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "Predicate.h"
#include "z3++.h"
#include "SortType.h"

#include "solvers/slah/HeapChunk.h"

using HeapType = pair<SortType*, SortType*>;

class Problem {
public:
	z3::context& z3_ctx;
    Problem(z3::context& ctx);
    virtual ~Problem();
    void setLogic(string logic) {m_logic = logic;}
    void setPredicate(Predicate* pred) {m_pred = pred;}
    void setPhi(z3::expr phi){m_phi = phi;}
    void setPsi(z3::expr psi){m_psi = psi;}
    void setHeap(SortType* src, SortType* dst) {m_heap.first = src; m_heap.second = dst;}

    string getLogic(){return m_logic;}
    z3::expr getPhi(){return m_phi;}
    z3::expr getPsi(){return m_psi;}
    Predicate* getPredicate(){return m_pred;}

    bool isSat();

    virtual void show();

    virtual void setHeapChunk(HeapChunk* hck) {}

protected:
    HeapType m_heap;
    z3::expr m_phi;
    z3::expr m_psi;
    Predicate* m_pred;
    string m_logic;
};


#endif
