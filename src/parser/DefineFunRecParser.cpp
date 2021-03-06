/*******************************************
*  @file  DefineFunRecParser.cpp      *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/DefineFunRecParser.h"
#include "component/Z3Buffer.h"
#include "component/Predicate.h"
#include "solvers/slid_set/Predicate_SLID_SET.h"
#include "solvers/slid_int/Predicate_SLID_INT.h"
#include "solvers/slah/Predicate_SLAH.h"
#include "solvers/slah/Problem_SLAH.h"

using namespace ComSpen;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void DefineFunRecParser::parse(Table* table) {
    Token* curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string fname = dynamic_cast<StrToken*>(curr)->value();
    
    parseParameters(table);

    FuncType* pf = new FuncType(z3_ctx, z3_buffer, fname);

    VarList vpars;
    table->topVar(vpars);
    z3::expr_vector pars(z3_ctx);
    z3::sort_vector domain(z3_ctx);
    for (auto par : vpars) {
        pars.push_back(z3_buffer.getVar(par));
        pf->addArg(par->getSort());
        domain.push_back(z3_buffer.getSort(par->getSort()));//
    }
    
    SortType* range = parseSort(table);

    pf->addArg(range);

    table->addFunc(fname, pf);
    
    z3::symbol fname_sym = z3_ctx.str_symbol(fname.c_str());//
    z3::sort rangesort = z3_buffer.getSort(range);
    z3::func_decl fun = z3_ctx.function(fname_sym, domain, rangesort);//

    // parse body
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string or_op = dynamic_cast<StrToken*>(curr)->value();
    if (or_op != "or") {
        throw SemanticException("the body must be 'or' function!", curr->row(), curr->col());
    }
    
    // base rule
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    // cout << "parse base" << endl;
    z3::expr base = parseExpr(table);
    // cout << base << endl;
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string exists_op = dynamic_cast<StrToken*>(curr)->value();
    if (exists_op != "exists") {
        throw SemanticException("the rule must be exists function!", curr->row(), curr->col());
    }

    // recursive rule
    // cout << "parser rec" << endl;
    z3::expr rec = parseExists(table);
    // cout << rec << endl;

    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    // action
    table->popVar();

    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    // action 
    table->popVar(); 
    // TODO generate predicate definition
    Predicate* pred;
    if(table->getProblem()->getLogic() == "QF_SLID_SET"){ 
    	pred = new Predicate_SLID_SET(z3_ctx, z3_buffer, fname, pars, base, rec);
	}else if(table->getProblem()->getLogic() == "QF_SLID_INT"){
		pred = new Predicate_SLID_INT(z3_ctx, fun, pars, base, rec);
	}else if(table->getProblem()->getLogic() == "QF_SLAH"){
		checkSLAHRecRule(table, rec, fname);
		pred = new Predicate_SLAH(z3_ctx, fun, pars, base, rec);
	}else{
		pred = new Predicate(z3_ctx, fname, pars, base, rec);
	}
    
    table->addPredicate(pred);
//cout<<"define-fun-rec done"<<endl;
}

void DefineFunRecParser::checkSLAHRecRule(Table* table, z3::expr rec, string fname){
	z3::expr body = rec.body();
	if (!body.is_app() || body.decl().name().str() != "sep") {
        throw SemanticException("'sep' is excepted in the recursive rule");
	}
	if (body.num_args() != 2) {
        throw SemanticException("two args is excepted in sep of the recursive rule");
	}
    Problem_SLAH* problem = (Problem_SLAH*)table->getProblem();
	if(problem->getHeapChunk() == nullptr){
		throw SemanticException("'hck' is not defined");
	}
	if(body.arg(0).decl().name().str() != problem->getHeapChunk()->get_name()){
		throw SemanticException("'hck' is excepted in the recursive rule");
	}
	if(body.arg(1).decl().name().str() != fname){
		string err_info = fname+" is excepted in the recursive rule";
		throw SemanticException(err_info);
	}
}
