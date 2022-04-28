/*******************************************
*  @file  AssertParser.cpp                 *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/AssertParser.h"

//extern z3::context z3_ctx;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void AssertParser::parse(Table* table) {
    parseExpr(table);

    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    // action
    z3::expr phi = table->topArg();
    table->popArg();

    if (phi.is_app() && phi.decl().name().str() == "not") {
        expr psi(z3_ctx);
		if(phi.num_args() > 0) psi = phi.arg(0);
        if(Z3_ast(psi) == nullptr||(psi.decl().name().str() != "and" && psi.decl().name().str() != "or")){
        	expr_vector items(z3_ctx);
        	if(Z3_ast(psi) != nullptr) items.push_back(psi);
        	psi = mk_and(items);
		}
        table->addPsi(psi);
    } else {
    	if(phi.decl().name().str() != "and" && phi.decl().name().str() != "or"){
        	expr_vector items(z3_ctx);
        	items.push_back(phi);
        	phi = mk_and(items);
		}
        table->addPhi(phi);
    }
//cout<<"assert done"<<endl;
}
