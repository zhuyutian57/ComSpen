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
  SortType* st = table->getSort(sort_name);
  assert(st != nullptr);
  std::string sort = sort_name;
  for(int i = 0; i < st->getArity(); i++) {
    curr = scanner->checkNext(SYMBOL_TOKEN, SYNTAX_ERROR_INFO[SYMBOL_TOKEN]);
    sort += "_" + dynamic_cast<StrToken*>(curr)->value();
  }
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
  scanner->checkNext(RIGHT_PAREN, SYNTAX_ERROR_INFO[RIGHT_PAREN]);
  table->addField(field_name, new Field(field_name, sort));
}