#if !defined(SLID_SOLVER_)
#define SLID_SOLVER_

#include "component/Problem.h"

#include "z3++.h"

class SlidSolver {

public:
  z3::context& z3_ctx;
  
  SlidSolver(z3::context& ctx);

  void solve(Problem* problem);
  z3::check_result checkSat(z3::expr& formula);

private:
  z3::solver z3_sol;

  z3::expr getAbs(z3::expr);

};

#endif