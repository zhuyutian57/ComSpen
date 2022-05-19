#include "parser/Parser.h"

using namespace ComSpen;

SyntaxErrorTable SYNTAX_ERROR_INFO = {
    "",
    "'(' is expected!",
    "')' is expected!",
    "keyword is expected!",
    "symbol is expected!",
    "string literal is expected!",
    "int literal is expected!",
    "float literal is expected!",
    "bit vector is expected!", 
    "EOF is expected!"
};

void Parser::set_input(string file) {
    std::ifstream* fin = new std::ifstream();
    fin->open(file, std::ios_base::binary);
    if (!fin->is_open()) {
        cout << "File " + file + " doesn't exists!" << endl;
        exit(-1);
    }
    scanner = new Scanner(*fin);
}