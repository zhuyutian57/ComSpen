#include "parser/Parser.h"

void Parser::setInput(string file) {
    std::ifstream* fin = new std::ifstream();
    fin->open(file, std::ios_base::binary);
    if (!fin->is_open()) {
        cout << "File " + file + " doesn't exists!" << endl;
        exit(-1);
    }
    scanner = new Scanner(*fin);
}