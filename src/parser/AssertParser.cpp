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

using namespace ComSpen;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void AssertParser::parse(Table* table) {
    this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    z3::expr phi = parseExpr(table);
    if (phi.is_app() && phi.decl().name().str() == "not") {
        z3::expr psi(z3_ctx);
		if(phi.num_args() > 0) psi = phi.arg(0);
        if(Z3_ast(psi) == nullptr||(psi.decl().name().str() != "and" && psi.decl().name().str() != "or")){
        	z3::expr_vector items(z3_ctx);
        	if(Z3_ast(psi) != nullptr) items.push_back(psi);
        	psi = z3::mk_and(items);
		}
        table->addPsi(psi);
    } else {
    	if(phi.decl().name().str() != "and" && phi.decl().name().str() != "or"){
        	z3::expr_vector items(z3_ctx);
        	items.push_back(phi);
        	phi = z3::mk_and(items);
		}
        table->addPhi(phi);
    }
    this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
//cout<<"assert done"<<endl;
}
