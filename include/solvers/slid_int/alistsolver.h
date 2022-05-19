#ifndef ALISTSOLVER_H_
#define ALISTSOLVER_H_

#include "listsolver.h"

namespace ComSpen {

class alistsolver: public listsolver {
protected:
    // match
    bool match_graph(listgraph& psi_g, listgraph& omega_g_i);
    z3::expr pred_unfold_ge1(z3::expr& atom, int i, z3::expr_vector& new_bools);

public:
    alistsolver(z3::context& ctx, Problem* problem) : listsolver(ctx, problem) {}

};

}

#endif // ALISTSOLVER_H_INCLUDED
