/*******************************************
*  @file  Problem.cpp                      *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "component/Problem.h"
#include "Types.h"

using namespace ComSpen;

Problem::Problem(z3::context& ctx):
    z3_ctx(ctx), m_phi(ctx), m_psi(ctx), m_pred(nullptr) {}

Problem::~Problem() {
    if (m_pred != nullptr) {
        delete m_pred;
    }
}

//void Problem::setSolver(SepSolver* ss) {
//    m_ss = ss;
//}

void Problem::show() {
	cout << "logic: " << m_logic << endl;
    cout << "heap: \n";
    cout << m_heap.first->getName() << " -> " << m_heap.second->getName() << endl;
    cout << "predicate: \n";
    m_pred->show();

    cout << "phi: " << m_phi << endl;
    // getAbsPhi();

    cout << "psi: " << m_psi << endl;
}


bool Problem::isSat() {
    return Z3_ast(m_psi) == nullptr;
}


