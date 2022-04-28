/*******************************************
*  @file  DeclHeapParser.cpp               *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/DeclHeapParser.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void DeclHeapParser::parse(Table* table) {
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);

    SortType* sort_src = parseSort(table);
    SortType* sort_dst = parseSort(table);

    // cout << sort_src->getName() << "->" << sort_dst->getName() << endl;
    table->getProblem()->setHeap(sort_src, sort_dst);

    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
//cout<<"declare-heap done"<<endl;
}
