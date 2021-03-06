/*******************************************
*  @file  SetInfoParser.cpp                * 
*  @brief    Brief file description        *
*                                          *
*  @author   Su WanYun                     *
*  @version  1.0                           *
*  @date     2021-3-1                     *
*                                          *
*******************************************/

#include "parser/SetInfoParser.h"
#include "component/Z3Buffer.h"
#include <iostream>

using namespace ComSpen;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @param parser Parameter description
 * @return Return parameter description
 */
void SetInfoParser::parse(Table* table) {
    Token* curr = scanner->nextToken();
    // Token* curr = parser.checkNext(STRING_TOKEN, SYNTAX_ERROR_INFO[STRING_TOKEN]);
    while (curr!=nullptr && curr->type() != RIGHT_PAREN) {
    	curr=scanner->nextToken();
        //curr = parser.checkNext(STRING_TOKEN, SYNTAX_ERROR_INFO[STRING_TOKEN]);
    }

    //curr = parser.checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]); 

//cout<<"set-info done"<<endl;
}
