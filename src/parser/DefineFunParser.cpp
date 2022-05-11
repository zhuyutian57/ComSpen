/*******************************************
*  @file  DefineFunParser.cpp         *
*  @brief  Brief file description          *
*                                          *
*  @author   Wanyun Su                     *
*  @version  1.0                           *
*  @date     2021-4-8                      *
*                                          *
*******************************************/

#include "parser/DefineFunParser.h"
//#include "component/Z3Buffer.h"
#include "solvers/slah/HeapChunk.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;
//extern Z3Buffer z3_buffer; 
//extern z3::context z3_ctx;

void DefineFunParser::parse(Table* table) {
	if(table->getProblem()->getLogic() != "QF_SLAH"){ 
    	throw SemanticException("Only QF_SLAH can use define-fun to define hck!");
	}
	
    Token* curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string fname = dynamic_cast<StrToken*>(curr)->value();
    parseParameters(table);

    FuncType* pf = new FuncType(z3_ctx,z3_buffer,fname);

    VarList vpars;
    table->topVar(vpars);
    expr_vector pars(z3_ctx);
    z3::sort_vector domain(z3_ctx);//
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

    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    z3::expr exp = parseExpr(table);
    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    // action
    table->popVar();
    
	int ex_size=0;

	if (exp.is_quantifier()) {
		ex_size=Z3_get_quantifier_num_bound(z3_ctx,Z3_ast(exp));
        exp = exp.body();
	}
    HeapChunk* hck = new HeapChunk(z3_ctx, fun, pars, exp, ex_size);
	//hck->show();
	
    table->addHeapChunk(hck);
//cout<<"define-fun done"<<endl;
}
