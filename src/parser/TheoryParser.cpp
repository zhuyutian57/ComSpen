/*******************************************
*  @file  Theorythis->parser->cpp                 *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/TheoryParser.h"
#include "Types.h"


#include <fstream>
#include <iostream>

using std::ifstream;
using std::cout;
using std::endl;

extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void TheoryParser::setTheory(string theory) {
  this->theory = theory;
  this->setInput(prefix + theory + ".smt2");
}

void TheoryParser::parse(Table* table) {

    Token* curr = nullptr;
    // (theory 
    curr = scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    if (dynamic_cast<StrToken*>(curr)->value() != "theory")
        throw SyntaxException("'theory' command is expected!", curr->row(), curr->col());
    // logic
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    if(dynamic_cast<StrToken*>(curr)->value() != theory)
        throw SemanticException(theory + " is expected!", curr->row(), curr->col());

    // :keyword info 
    while ( (curr = scanner->nextToken()) != nullptr 
        && curr->type() == KEYWORD_TOKEN) {
        string key = dynamic_cast<StrToken*>(curr)->value();
        if (key == "sorts") parseSorts(table);
        else if (key == "funs") parseFuns(table);
        else {
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
            table->addTheoryInfo(key, value);
        }
    }

    // emp is a fix var
    if (theory == "QF_SLID_LC") {
        string emp = "emp";
        string sort = "Space";
        table->addVar(new Var(z3_ctx, z3_buffer, emp, table->getSort(sort)));
    }
}

SortType* TheoryParser::parseSort() {
    Token* curr = nullptr;
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string s = dynamic_cast<StrToken*>(curr)->value();
    curr = scanner->checkNext(INT_TOKEN, SYNTAX_ERROR_INFO[INT_TOKEN]);
    int n = dynamic_cast<IntToken*>(curr)->value();
    return new SortType(z3_ctx, s, n);
}

void TheoryParser::parseSorts(Table* table) {
    Token* curr = nullptr;
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    while((curr = scanner->nextToken()) != nullptr
            && curr->type() == LEFT_PAREN) {
        SortType* sort = parseSort();
        table->addSort(sort->getName(), sort);
        scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    }
    assert(curr->type() == RIGHT_PAREN);
}

vector<SortType*> TheoryParser::parseSortsList(Table* table) {
    vector<SortType*> sortsList;
    Token* curr = nullptr;
    while((curr = scanner->nextToken()) != nullptr
            && curr->type() != RIGHT_PAREN) {
        SortType* st;
        if (curr->type() == LEFT_PAREN) {
            curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
            string name = dynamic_cast<StrToken*>(curr)->value();
            st = new SortType(table->getSort(name));
            for(int i = 0; i < st->getArity(); i++) {
                curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
                st->addSubType(dynamic_cast<StrToken*>(curr)->value());
            }
            scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
        } else {
            string name = dynamic_cast<StrToken*>(curr)->value();
            if (curr->type() == KEYWORD_TOKEN) name = ":" + name;
            st = new SortType(z3_ctx, name, 0);
        }
        sortsList.push_back(st);
    }
    return sortsList;
}

FuncType* TheoryParser::parseFun(Table* table) {
    Token* curr = nullptr;
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string symbol = dynamic_cast<StrToken*>(curr)->value();
    FuncType* fun;
    if(symbol == "par") {
        fun = new ParFuncType(z3_ctx, z3_buffer, "");
        scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
        vector<SortType*> parsTypes = parseSortsList(table);
        for(SortType* st : parsTypes) fun->addPar(st);
        scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
        curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        fun->setName(dynamic_cast<StrToken*>(curr)->value());
    } else
        fun = new FuncType(z3_ctx, z3_buffer, symbol);
    vector<SortType*> argsTypes = parseSortsList(table);
    if (symbol == "par")
        scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    // Set attribute
    if (argsTypes.back()->getName()[0] == ':') {
        fun->setAttr(argsTypes.back()->getName().substr(1));
        argsTypes.pop_back();
    } else {
        fun->setAttr("NONE");
        if (fun->getName() == "-")
            fun->setName("--");
    }
    for(SortType* st : argsTypes) fun->addArg(st);
    return fun;
}

void TheoryParser::parseFuns(Table* table) {
    Token* curr = nullptr;
    scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    while((curr = scanner->nextToken()) != nullptr
            && curr->type() == LEFT_PAREN) {
        FuncType* fun = parseFun(table);
        table->addFunc(fun->getName(), fun);
    }
    assert(curr->type() == RIGHT_PAREN);
}
