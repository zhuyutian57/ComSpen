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
        string cmd = dynamic_cast<StrToken*>(curr)->value();
        cmd_parser = factory.getCommandParser(cmd);
        // check
        if (cmd_parser == nullptr) {
            throw SemanticException(
                cmd + " is unsupported command!", curr->row(), curr->col());
        }
        // cout << cmd << endl;
        cmd_parser->setScanner(this->scanner);
        cmd_parser->parse(table);
        // cout << "done\n";
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

z3::expr CommandParser::parseExpr(Table* table) {
    Token* curr = nullptr;
    curr = this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    string fname = dynamic_cast<StrToken*>(curr)->value();

    // ignore (_ emp Int data)
    if (fname == "_") {
        this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        this->scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
        this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
        return z3_ctx.bool_val(true);
    }
    FuncType* pf = table->getFunc(fname);
    assert(pf != nullptr);
    z3::expr_vector args(z3_ctx);
    SortList args_types;
    while((curr = this->scanner->nextToken()) != nullptr
            && curr->type() != RIGHT_PAREN) {
        if(curr->type() == LEFT_PAREN) {
            args.push_back(parseExpr(table));
        } else if(curr->type() == INT_TOKEN) {
            int val = dynamic_cast<IntToken*>(curr)->value();
            args.push_back(z3_ctx.int_val(val));
        } else if(curr->type() == SYMBOL_TOKEN) {
            string id = dynamic_cast<StrToken*>(curr)->value();
            Var* pv = table->getVar(id);
            args.push_back(z3_buffer.getVar(pv));
        }
        std::string arg_sort = args.back().get_sort().to_string();
        SortType* arg_type = table->getSort(arg_sort);
        assert(arg_type != nullptr);
        args_types.push_back(arg_type);
    }
    assert(curr->type() == RIGHT_PAREN);
    return this->mk_app(pf, args, args_types, table);
}

z3::expr CommandParser::parseExists(Table* table) {
    parseParameters(table);

    VarList vlist;
    table->topVar(vlist);

    z3::expr_vector xs(z3_ctx);
    for (auto ve : vlist) {
        xs.push_back(z3_buffer.getVar(ve));
    }
    
    this->scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
    z3::expr body = parseExpr(table);
    this->scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
    
    return z3::exists(xs, body);
}


z3::expr CommandParser::mk_app(
    FuncType* pf,
    z3::expr_vector args,
    SortList& args_types,
    Table* table) {
    string op = pf->getName();
    if (op == "not") return !args[0];
    else if (op == "and") return z3::mk_and(args);
    else if (op == "or") return z3::mk_or(args);
    else if (op == "=") return args[0] == args[1];
    else if (op == "+") return z3::sum(args);
    else if (op == "-") {
        if (args.size() == 1) return -args[0];
        z3::expr res(z3_ctx);
        res = args[0];
        for(int i = 1; i < args.size(); i++)
            res =  res - args[i];
        return res;
    } else if (op == "*") {
        z3::expr res(z3_ctx);
        res = args[0];
        for(int i = 1; i < args.size(); i++)
            res =  res * args[i];
        return res;
    } else if (op == "<=") return args[0] <= args[1];
    else if (op == "<") return args[0] < args[1];
    else if (op == ">=") return args[0] >= args[1];
    else if (op == ">") return args[0] > args[1];
    else {
        z3::func_decl fd = z3_buffer.getFuncDecl(pf, args_types, table);
        return fd(args);
    }
    std::cout << "no such operator!!!" << std::endl;
    assert(false);
}
