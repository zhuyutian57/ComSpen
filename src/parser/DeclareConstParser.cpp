/*******************************************
*  @file  DeclareConstParser.cpp              *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/DeclareConstParser.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void DeclareConstParser::parse(Table* table) {
    Token* curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string vname = dynamic_cast<StrToken*>(curr)->value();
    
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string vsort = dynamic_cast<StrToken*>(curr)->value();

    curr = scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
     
    SortType* sort = table->getSort(vsort);

    Var* pv = new Var(z3_ctx, z3_buffer, vname, sort);
    table->addVar(pv);
//cout<<"declare-const done"<<endl;
}
