/*******************************************
*  @file  SetLogicParser.cpp               * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/SetLogicParser.h"
#include "parser/LogicParser.h"
#include "parser/TheoryParser.h"
//#include "component/Z3Buffer.h"
#include <iostream>

#include "solvers/slah/Problem_SLAH.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;
//extern Z3Buffer z3_buffer;

using std::cout;
using std::endl;


/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @param parser Parameter description
 * @return Return parameter description
 */
void SetLogicParser::parse(Table* table) {
    Token* curr = scanner->nextToken();
    if (curr->type() != STRING_TOKEN && curr->type() != SYMBOL_TOKEN) {
        throw SemanticException("logic name is expected!", curr->row(), curr->col());
    }
    //
    string logic = dynamic_cast<StrToken*>(curr)->value();

    if (logic == "QF_SLAH")
        table->setProblem(new Problem_SLAH(z3_ctx));
    else
        table->setProblem(new Problem(z3_ctx));
	table->addLogic(logic); 

    // cout << "logic: " <<  logic << endl;

    LogicParser logic_parser(z3_ctx, z3_buffer);
    logic_parser.setLogic(logic);
    logic_parser.parse(table);
    for (string theory : table->getTheories()) {
        // cout << "theory: " << theory << endl;
        TheoryParser theory_parser(z3_ctx, z3_buffer);
        theory_parser.setTheory(theory);
        theory_parser.parse(table);
    }
    curr = scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]); 
    // action: init context by logic file
    z3_ctx.check_error();
    z3_buffer.init(table);
}
