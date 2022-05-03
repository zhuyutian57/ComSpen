#include "parser/DeclareFunParser.h"


extern SyntaxErrorTable SYNTAX_ERROR_INFO;

void DeclareFunParser::parse(Table* table) {
  Token* curr = nullptr;
  curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
  std::string field_name = dynamic_cast<StrToken*>(curr)->value();
  
  // parameters must be empty
  scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
  scanner->checkNext(LEFT_PAREN, SYNTAX_ERROR_INFO[LEFT_PAREN]);

  curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
  std::string sort_name = dynamic_cast<StrToken*>(curr)->value();
  int n = table->getSort(sort_name)->getArity();
  SortType* st = new SortType(z3_ctx, sort_name, n);
  for(int i = 0; i < n; i++) {
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    st->addSubType(dynamic_cast<StrToken*>(curr)->value());
  }
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);

  // it seams field is redundant!!!
  Field* field = new Field(field_name, st);
  table->addField(field_name, field);

  // field will be recognized as const(var)
  Var* fv = new Var(z3_ctx, z3_buffer, field_name, st);
  table->addVar(fv);

  if (table->getSort(st->getSort()) == nullptr)
    table->addSort(st->getSort(), st);
}