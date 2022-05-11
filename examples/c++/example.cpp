#include <iostream>

#include "slah_api.h"
#include "z3++.h"

void test_slah_api() {
  z3::context ctx;
  z3::expr a = ctx.int_const("a");
  z3::expr b = ctx.int_const("b");
  z3::expr c = ctx.int_const("c");
  z3::expr d = ctx.int_const("d");
  z3::expr e = ctx.int_const("e");
  z3::expr f = ctx.int_const("f");
  
  z3::expr pure =
    (a != b) && (e == f) && (e == c);
  
  z3::expr atom1 = slah_api::newPto(a, b);
  z3::expr atom2 = slah_api::newBlk(b, f);
  z3::expr atom3 = slah_api::newBlk(c, d);
  z3::expr_vector atoms(ctx);
  atoms.push_back(atom1);
  atoms.push_back(atom2);
  atoms.push_back(atom3);
  z3::expr space = slah_api::newSep(atoms);
  
  z3::expr formula = pure && space;
  std::cout << "slah:\n";
  std::cout << " problem: " << formula << std::endl;
  std::cout << " result: " << slah_api::checkSat(formula) << std::endl;
  std::cout << std::endl;
}

int main () {
  test_slah_api();
  return 0;
}