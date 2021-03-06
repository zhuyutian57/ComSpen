#if !defined(PARSER_)
#define PARSER_

#include "Table.h"
#include "Types.h"
#include "z3++.h"

#include <iostream>
#include <fstream>

namespace ComSpen {

class Parser {

public:
  z3::context& z3_ctx;
	Z3Buffer& z3_buffer;
  Parser(z3::context& ctx, Z3Buffer& buffer)
    : z3_ctx(ctx), z3_buffer(buffer) {}
  
  virtual void parse(Table* table) {}

protected:
  Scanner* scanner;
  
  void set_input(std::string file);
};

}

#endif
