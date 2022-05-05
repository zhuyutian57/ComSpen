#include "parser/Table.h"
#include "parser/CommandParser.h"
#include "parser/TheoryParser.h"
#include "scanner/Scanner.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

void check(const char* file) {
    TokenScanner::initNormalizedTable();
    TokenScannerFactory factory;

	z3::context z3_ctx;
	Z3Buffer z3_buffer(z3_ctx);
    Table* table = new Table(z3_ctx, z3_buffer);

    CommandParser* parser =
        new CommandParser(z3_ctx, z3_buffer);
    parser->setFile(std::string(file));
    try {
        parser->parse(table);
    } catch(std::exception& e) {
        cout << e.what() << endl;
        exit(-1);
    }
}

void readTheory(const char* theory) {
    TokenScanner::initNormalizedTable();
    TokenScannerFactory factory;

	z3::context z3_ctx;
	Z3Buffer z3_buffer(z3_ctx);
    Table* table = new Table(z3_ctx, z3_buffer);

    TheoryParser* parser =
        new TheoryParser(z3_ctx, z3_buffer);
    parser->setTheory(std::string(theory));
    try {
        parser->parse(table);
    } catch(std::exception& e) {
        cout << e.what() << endl;
        exit(-1);
    }
    table->show();
}


int main(int argc, const char *argv[])
{
    if (argc == 2) {
        cout << "File: " << argv[1] << endl;
        check(argv[1]);
    } else if (argc == 3) {
        if (string(argv[1]) == "-theory") {
            cout << "File: " << argv[2] << endl;
            readTheory(argv[2]);
        }
    }
    return 0;
}
