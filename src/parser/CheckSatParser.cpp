/*******************************************
*  @file  CheckSatParser.cpp               *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "parser/CheckSatParser.h"
#include "solvers/slid/SlidSolver.h"
#include "solvers/slid_set/SepSolver.h"
#include "solvers/slid_int/listsolver.h"
#include "solvers/slid_int/alistsolver.h"
#include "solvers/slah/PASolver.h"
#include "solvers/slah/Problem_SLAH.h"

using namespace ComSpen;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void CheckSatParser::parse(Table* table) {
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

  z3_buffer.setVarEnv(table);
  Problem* problem = table->getProblem();
  problem->show();
  if(problem->getLogic()=="QF_SLID_SET"){
   	SepSolver ss(z3_ctx,z3_buffer);
   	ss.setProblem(problem);
   	ss.solve();
	}else if(problem->getLogic()=="QF_SLID_INT"){
		Predicate_SLID_INT *pred = dynamic_cast<Predicate_SLID_INT *>(problem->getPredicate()); 
		if (pred->get_pars().size() == 2) {
            alistsolver ss(z3_ctx, problem);
            ss.solve();
        } else {
            listsolver ss(z3_ctx, problem);
			ss.solve();
        }
	}else if(problem->getLogic()=="QF_SLAH"){
    	PASolver ss(z3_ctx);
    	ss.setProblem((Problem_SLAH*)problem);
    	ss.solve();
	} else if(problem->getLogic() == "QF_SLID_TYPED") {
		SlidSolver sol(z3_ctx, problem);
		sol.solve();
	}else{
		std::cout<<"No solver for the logic"<<std::endl;
	}
}
