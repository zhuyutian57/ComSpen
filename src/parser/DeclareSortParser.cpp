/*******************************************
*  @file  DeclareSortParser.cpp               *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/DeclareSortParser.h"
#include "component/SortType.h"
//#include "component/Z3Buffer.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;
//extern Z3Buffer z3_buffer;

/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @param parser Parameter description
 * @return Return parameter description
 */
void DeclareSortParser::parse(Table* table) {
    Token* curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string sort = dynamic_cast<StrToken*>(curr)->value();
    int row = curr->row();
    int col = curr->col();

    curr = scanner->checkNext(INT_TOKEN, SYNTAX_ERROR_INFO[INT_TOKEN]);
    int snum = dynamic_cast<IntToken*>(curr)->value();

    curr = scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

    SortType* p_sort = new SortType(z3_ctx, sort, snum);
    table->addSort(sort, p_sort, row, col);
    z3_buffer.getSort(p_sort);

	string nil = "nil";
	if(table->getVar(nil) == nullptr){
		Var* pv = new Var(z3_ctx, z3_buffer, nil, p_sort);
    	table->addVar(pv);	
	}
	string setint = "SetInt";
	string emptyset = "emptyset";
    if(table->getSort(setint) != nullptr && table->getVar(emptyset) == nullptr){
    	SortType* ps = table->getSort(setint);
    	Var* pv = new Var(z3_ctx, z3_buffer, emptyset, ps);
    	table->addVar(pv);	
	}
}

