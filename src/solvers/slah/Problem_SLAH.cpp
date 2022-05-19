#include "solvers/slah/Problem_SLAH.h"

using namespace ComSpen;

Problem_SLAH::Problem_SLAH(z3::context& ctx)
    : Problem(ctx), m_hck(nullptr) {}

Problem_SLAH::~Problem_SLAH() {
    if (m_hck != nullptr) {
        delete m_hck;
    }
}

void Problem_SLAH::show() {
	cout << "Logic: " << m_logic << endl;
    cout << "Heap: \n";
    cout << m_heap.first->getName() << " -> " << m_heap.second->getName() << endl;
    cout << "Predicate: \n";
    m_pred->show();
    cout << "HeapChunk: \n";
    m_hck->show();
    cout << "Phi: " << m_phi << endl;
    cout << "Psi: " << m_psi << endl;
}


