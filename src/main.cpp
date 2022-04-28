#include "parser/Table.h"
#include "parser/CommandParser.h"
#include "parser/TheoryParser.h"
#include "Scanner.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

void check(string& file) {

    TokenScanner::initNormalizedTable();
    TokenScannerFactory factory;

	z3::context z3_ctx;
	Z3Buffer z3_buffer(z3_ctx);
    Table* table = new Table(z3_ctx, z3_buffer);

    CommandParser* parser =
        new CommandParser(z3_ctx, z3_buffer);
    parser->setFile(file);
    try {
        parser->parse(table);
    } catch(std::exception& e) {
        cout << e.what() << endl;
        exit(-1);
    }

}

void readTheory(string& theory) {

}


int main(int argc, const char *argv[])
{
    if (argc == 2) {
        string file_name = argv[1];
        cout << "file: " << file_name << endl;
        check(file_name);
    } 
    return 0;
}
