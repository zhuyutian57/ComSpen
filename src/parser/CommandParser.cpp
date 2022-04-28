/*******************************************
*  @file  CommandParser.cpp                *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/CommandParser.h"
#include "parser/CommandParserFactory.h"
//#include "component/Z3Buffer.h"

extern SyntaxErrorTable SYNTAX_ERROR_INFO;
//extern z3::context z3_ctx;
//extern Z3Buffer z3_buffer;

void CommandParser::setScanner(Scanner* scanner) { this->scanner = scanner; }
void CommandParser::setFile(string file) { this->setInput(file); }

void CommandParser::parse(Table* table) {
    // parse ( and symbol
    this->scanner = scanner;
    CommandParserFactory factory(z3_ctx, z3_buffer);
    CommandParser* cmd_parser;
    Token* curr = nullptr;
    while((curr = this->scanner->nextToken()) != nullptr
    && curr->type() == LEFT_PAREN) {
        curr = this->scanner->checkNext(SYMBOL_TOKEN, "command symbol is excepted!");
        cmd_parser = factory.getCommandParser(dynamic_cast<StrToken*>(curr)->value());
        // check
        if (cmd_parser == nullptr) {
            throw SemanticException("unsupported command!", curr->row(), curr->col());
        }
        cmd_parser->setScanner(this->scanner);
        cmd_parser->parse(table);
    }
    if (curr != nullptr && curr->type() != EOF_TOKEN) {
        throw SemanticException("'(' is expected!", curr->row(), curr->col());
    }
}

SortType* CommandParser::parseSortDecl(Table* table) {
    Token* curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string sort = dynamic_cast<StrToken*>(curr)->value();
    // int row = curr->row();
    // int col = curr->col();

    curr = this->scanner->checkNext(INT_TOKEN, SYNTAX_ERROR_INFO[INT_TOKEN]);
    int snum = dynamic_cast<IntToken*>(curr)->value();

    curr = this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

    SortType* p_sort = new SortType(z3_ctx, sort, snum);
    // addSort(sort, p_sort, row, col);
    return p_sort;
}


void CommandParser::parseSortDeclList(Table* table, SortTypeList& st_list) {
    // Token* curr = this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    Token* curr;
    while ((curr = this->scanner->nextToken()) != nullptr 
                && curr->type() == LEFT_PAREN) {
        st_list.push_back(parseSortDecl(table));
    }

    if (curr == nullptr || curr->type() != RIGHT_PAREN) {
        throw SyntaxException(SYNTAX_ERROR_INFO[RIGHT_PAREN], curr->row(), curr->col());
    }
}

void CommandParser::parseSelectorDecl(Table* table, SelectorDec& sel_dec) {
    Token* curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string key = dynamic_cast<StrToken*>(curr)->value();

    curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string sort = dynamic_cast<StrToken*>(curr)->value();

    curr = this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

    sel_dec.first = key;
    sel_dec.second = table->getSort(sort);
}


void CommandParser::parseSelectorDeclList(Table* table, SelectorDecList& sd_list) {
    // Token* curr = this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    Token* curr;
    while((curr = this->scanner->nextToken()) != nullptr 
    && curr->type() == LEFT_PAREN) {
        SelectorDec sd;
        parseSelectorDecl(table, sd);
        sd_list.push_back(sd);
    }

    if (curr == nullptr || curr->type() != RIGHT_PAREN) {
        throw SyntaxException(SYNTAX_ERROR_INFO[RIGHT_PAREN], curr->row(), curr->col());
    }
}

void CommandParser::parseConstructorDecl(Table* table, ConstructorDec& con_dec) {
    Token* curr;
    curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    
    string key = dynamic_cast<StrToken*>(curr)->value();

    SelectorDecList sd_list;
    parseSelectorDeclList(table, sd_list);

    this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

    con_dec.first = key;
    con_dec.second = sd_list;
}

void CommandParser::parseConstructorDeclList(Table* table, ConstructorDecList& cd_list) {
    Token* curr;
    while ((curr = this->scanner->nextToken()) != nullptr 
    && curr->type() == LEFT_PAREN) {
        ConstructorDec cd;
        parseConstructorDecl(table, cd);
        cd_list.push_back(cd);
    }

    if (curr == nullptr || curr->type() != RIGHT_PAREN) {
        throw SyntaxException(SYNTAX_ERROR_INFO[RIGHT_PAREN], curr->row(), curr->col());
    }
}

SortType* CommandParser::parseSort(Table* table) {
    Token* curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string sort = dynamic_cast<StrToken*>(curr)->value();
    SortType* sort_ptr = table->getSort(sort);
    if (sort_ptr == nullptr) {
        throw SemanticException("sort '" + sort + "' not defined!", curr->row(), curr->col());
    }
    return sort_ptr; 
}

void CommandParser::parseParameters(Table* table) {
    Token* curr = this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    table->addVarScope();
    while ((curr = this->scanner->nextToken()) != nullptr
            && curr->type() == LEFT_PAREN) {
        curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        string pname = dynamic_cast<StrToken*>(curr)->value();
        SortType* sort = parseSort(table);
        this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
        // action
        Var* pa = new Var(z3_ctx, z3_buffer, pname, sort);
        table->addVar(pa);
    }
}

void CommandParser::_parseExpr(Table* table) {
    Token* curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string op = dynamic_cast<StrToken*>(curr)->value();
    if (op == "_") {
        // parse (_ emp A B)
        curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        // string emp = dynamic_cast<StrToken*>(cur)->value();
        curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        curr = this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
        m_paren_counter --;
        return ;
    }
    
    if(op == "exists"){
    	parseExists(table);
    	return;
	}
//    FuncType* pf =  getFunc(op);
//    if (pf != nullptr) {
//        cout << "found function: "; pf->show(); cout << endl;
//    } else {
//        cout << "not supported op: " << op << endl;
//    }
    table->pushOp(op);
    while ((curr = this->scanner->nextToken()) != nullptr) {
        switch (curr->type()) {
            case LEFT_PAREN:
                m_paren_counter ++;
                _parseExpr(table);
                break;
            case RIGHT_PAREN:
                m_paren_counter --;
                table->mkApp();
                break;
            case INT_TOKEN: {
                int val = dynamic_cast<IntToken*>(curr)->value();
                expr ie = z3_ctx.int_val(val);
                table->pushArg(ie);
                break;
            }
            case FLOAT_TOKEN: {
                float val = dynamic_cast<FloatToken*>(curr)->value();
                expr fe = z3_ctx.real_val((int)val); // TODO
                table->pushArg(fe);
                break;
            }
            case SYMBOL_TOKEN:
            {
                string id = dynamic_cast<StrToken*>(curr)->value();
                if (id == "true") table->pushArg(z3_ctx.bool_val(true));
                else if (id == "false") table->pushArg(z3_ctx.bool_val(false));
                else {
                    Var* pv = table->getVar(id);
                    expr ve = z3_buffer.getVar(pv);
                    table->pushArg(ve);
                }
                break;
            }
            default:
                throw SemanticException("the argument is not valid!", curr->row(), curr->col());
        }

        if (m_paren_counter == 0) break;
    }
}

void CommandParser::parseExpr(Table* table) {
    this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    m_paren_counter = 1;
    _parseExpr(table);
}

void CommandParser::parseExists(Table* table) {
    parseParameters(table);

    VarList vlist;
    table->topVar(vlist);

    expr_vector evars(z3_ctx);
    for (auto ve : vlist) {
        evars.push_back(z3_buffer.getVar(ve));
    }

    parseExpr(table);
    this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    
    // exists
    expr ebody = table->topArg();
    table->popArg();
    expr rec = exists(evars, ebody);
    table->pushArg(rec);
}

