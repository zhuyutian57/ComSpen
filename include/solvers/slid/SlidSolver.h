#if !defined(SLID_SOLVER_)
#define SLID_SOLVER_

#include "component/Problem.h"

#include "z3++.h"

class SlidSolver {

public:
  z3::context& z3_ctx;

  SlidSolver(z3::context& ctx, Problem* problem);

  void solve();
  z3::model getModel();
  z3::check_result checkSat(z3::expr& formula);

private:
  z3::solver z3_sol;
  Problem* problem;

  z3::check_result check_sat(z3::expr formula);
  
  bool is_fun(z3::expr& formula, std::string name);
  bool is_loc(z3::expr& formula);
  z3::expr head(z3::expr formula);
  z3::expr tail(z3::expr formula);
  z3::expr loc_to_int(z3::expr formula);

  z3::expr get_abs(z3::expr formula);
  z3::expr get_abs_emp(z3::expr& formula);
  z3::expr get_abs_ssep(z3::expr& formula);
  z3::expr get_abs_pto(z3::expr& formula);
  z3::expr get_abs_blk(z3::expr& formula);
  // z3::expr get_abs_ref(z3::expr& formula);
  // z3::expr get_abs_sref(z3::expr& formula);

};

#endif