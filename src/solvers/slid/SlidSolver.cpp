#include "solvers/slid/SlidSolver.h"

SlidSolver::SlidSolver(z3::context& ctx, Problem* problem)
  : z3_ctx(ctx), z3_sol(ctx), problem(problem) {}

void SlidSolver::solve() {
  z3::check_result res;
  z3::expr phi = problem->getPhi();
  assert(problem->isSat());
  if (problem->isSat())
    res = check_sat(phi);
  cout << res << endl;
  if (res == z3::sat)
    cout << getModel() << endl;
}

z3::model SlidSolver::getModel() {
  return z3_sol.get_model();
}

z3::check_result SlidSolver::checkSat(z3::expr& formula) {
  return check_sat(formula);
}

z3::check_result SlidSolver::check_sat(z3::expr formula) {
  z3::expr abs = get_abs(formula);
  z3_sol.reset(); z3_sol.add(abs);
  z3::check_result res = z3_sol.check();
  return res;
}

z3::expr SlidSolver::get_abs(z3::expr formula) {
  z3::expr abs(z3_ctx);
  if (is_space(formula)) {
    std::string fun = formula.decl().name().str();
    if (is_fun(formula, "emp")) abs = get_abs_emp(formula);
    else if (is_fun(formula, "ssep")) abs = get_abs_ssep(formula);
    else if (is_fun(formula, "pto")) abs = get_abs_pto(formula);
    else if (is_fun(formula, "blk")) abs = get_abs_blk(formula);
    else {
      cout << "no such fun : " << fun << endl;
      assert(false);
    }
  } else if (formula.is_and() || formula.is_or()) {
    for(z3::expr f : formula.args()) {
      z3::expr abs_f = get_abs(f);
      if (Z3_ast(abs) == 0) abs = abs_f;
      else abs =
        (formula.is_and() ?
          abs && abs_f : abs || abs_f);
    }
  } else abs = formula;
  return abs;
}

bool SlidSolver::is_fun(z3::expr& formula, std::string name) {
  assert(formula.is_app());
  return formula.decl().name().str() == name;
}
bool SlidSolver::is_loc(z3::expr& formula) {
  return formula.get_sort().to_string() == "Loc";
}
bool SlidSolver::is_space(z3::expr& formula) {
  if (!formula.is_app()) return false;
  std::string name = formula.decl().name().str();
  return name == "ssep" || name == "pto" || name == "blk";
}

z3::expr SlidSolver::head(z3::expr formula) {
  assert(formula.is_app());
  std::string name = formula.decl().name().str();
  assert(name == "pto" || name == "blk");
  return formula.arg(0); 
}
z3::expr SlidSolver::tail(z3::expr formula) {
  assert(formula.is_app());
  std::string name = formula.decl().name().str();
  assert(name == "pto" || name == "blk");
  if (name == "blk")
    return formula.arg(1);
  return formula.arg(0);
}

z3::expr SlidSolver::loc_to_int(z3::expr formula) {
  assert(is_loc(formula));
  std::string name = formula.decl().name().str();
  return z3_ctx.int_const(name.c_str());
}

z3::expr SlidSolver::get_abs_emp(z3::expr& formula) {
  return  z3_ctx.bool_val(true);
}

z3::expr SlidSolver::get_abs_ssep(z3::expr& formula) {
  z3::expr abs(z3_ctx);
  for (z3::expr f : formula.args()) {
    z3::expr abs_atom = get_abs(f);
    if(Z3_ast(abs) == 0) abs = abs_atom;
    else abs = abs && abs_atom;
  }
  for (int i = 0; i < formula.num_args(); i++) {
    z3::expr atomi = formula.arg(i);
    z3::expr hi = loc_to_int(head(atomi));
    z3::expr ti = loc_to_int(tail(atomi));
    bool type_i = is_fun(atomi, "pto");
    for (int j = i + 1; j < formula.num_args(); j++) {
        z3::expr atomj = formula.arg(j);
        z3::expr hj = loc_to_int(head(atomj));
        z3::expr tj = loc_to_int(tail(atomj));
        bool type_j = is_fun(atomj, "pto");
        
        if (type_i && type_j) abs = abs && hi != hj;
        else if (type_i) abs = abs && (hi < hj || hi >= tj);
        else if (type_j) abs = abs && (hj < hi || hj >= ti);
        else abs = abs && (hj >= ti || hi >= tj);
    }
  }
  return abs;
}

//TODO consider every field
z3::expr SlidSolver::get_abs_pto(z3::expr& formula) {
  z3::expr abs(z3_ctx);
  z3::expr x = formula.arg(0);
  if (is_loc(x)) x = loc_to_int(x);
  abs = (x > 0);
  assert(formula.num_args() > 1);
  // for (int i = 1; i < formula.num_args(); i++) {
  //   abs = abs && get_abs(formula.arg(i));
  // }
  return abs;
}

z3::expr SlidSolver::get_abs_blk(z3::expr& formula) {
  z3::expr abs(z3_ctx);
  z3::expr x = formula.arg(0);
  z3::expr y = formula.arg(1);
  if (is_loc(x)) x = loc_to_int(x);
  if (is_loc(y)) y = loc_to_int(y);
  abs = x > 0 && x <= y;
  return abs;
}

