/*******************************************
*  @file  DeclareDatatypesParser.cpp          *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/DeclareDatatypesParser.h"

using namespace ComSpen;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void DeclareDatatypesParser::parse(Table* table) {
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    SortTypeList st_list;
    parseSortDeclList(table, st_list);
    // parse datatype
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    ConstructorDecList cd_list;
    parseConstructorDeclList(table, cd_list);

    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

    // action
    // 1. add sort (st_list.size() == 1)
    // assert(st_list.size() == 1);
    SortType* ptr = st_list[0];
    table->addSort(ptr->getName(), ptr);
    // add z3 buffer
    z3_buffer.getSort(ptr);
    // 2. add func_decl (cd_list.size() == 1)
    ConstructorDec cd = cd_list[0];
    FuncType* pf = new FuncType(z3_ctx,z3_buffer,cd.first);
    for (auto item : cd.second) {
        pf->addArg(item.second);
    }
    pf->addArg(ptr);
    table->addFunc(cd.first, pf);
//cout<<"declare-datatypes done"<<endl;
}
