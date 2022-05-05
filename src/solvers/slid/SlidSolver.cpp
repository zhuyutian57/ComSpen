#include "solvers/slid/SlidSolver.h"

SlidSolver::SlidSolver(z3::context& ctx)
  : z3_ctx(ctx), z3_sol(ctx) {}

