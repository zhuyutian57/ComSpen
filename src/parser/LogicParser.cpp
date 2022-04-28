/*******************************************
*  @file  LogicParser.cpp                  *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "Types.h"
#include "parser/LogicParser.h"

#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void LogicParser::setLogic(string logic) {
    this->logic = logic;
    this->setInput(prefix + logic + ".smt2");
}

void LogicParser::parse(Table* table) {
    Token* curr = nullptr;
    // ( logic
    curr = scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    if (dynamic_cast<StrToken*>(curr)->value() != "logic")
        throw SyntaxException("'logic' command is expected!", curr->row(), curr->col());
    // logic
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    if (dynamic_cast<StrToken*>(curr)->value() != logic)
        throw SemanticException(logic + " is expected!", curr->row(), curr->col());

    // :keyword info 
    while ( (curr = scanner->nextToken()) != nullptr 
        && curr->type() == KEYWORD_TOKEN) {
        string key = dynamic_cast<StrToken*>(curr)->value();
        if (key == "theories") {
            // :theories ()
            scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
            while (  (curr = scanner->nextToken()) != nullptr 
                && curr->type() == SYMBOL_TOKEN) {
                // read theory
                string theory = dynamic_cast<StrToken*>(curr)->value();
                table->addTheory(theory);
            }
            if (curr == nullptr || curr->type() != RIGHT_PAREN) {
                throw SyntaxException(SYNTAX_ERROR_INFO[SYMBOL_TOKEN] + " or " + SYNTAX_ERROR_INFO[RIGHT_PAREN], 
                    curr->row(), curr->col());
            }
        } else {
            // description info :key "description"
            string key = dynamic_cast<StrToken*>(curr)->value();
            string value;
            curr = scanner->nextToken();
            if (curr->type() == STRING_TOKEN) {
                value = dynamic_cast<StrToken*>(curr)->value();
            } else if (curr->type() == INT_TOKEN) {
                value = to_string(dynamic_cast<IntToken*>(curr)->value());
            } else if (curr->type() == FLOAT_TOKEN) {
                value = to_string(dynamic_cast<FloatToken*>(curr)->value());
            } else {
                string info = "description info is expected!";
                throw SyntaxException(info, curr->row(), curr->col());
            }
            table->addLogicInfo(key, value);
        }
    }
    if (curr == nullptr && curr->type() != RIGHT_PAREN) {
        throw SyntaxException(SYNTAX_ERROR_INFO[KEYWORD_TOKEN] + " or " + SYNTAX_ERROR_INFO[RIGHT_PAREN], 
            curr->row(), curr->col());
    }
}
