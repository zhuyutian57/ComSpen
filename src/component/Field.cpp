#include "component/Field.h"

Field::Field(std::string name, SortType* sort)
  : name(name), sort(sort) {}

SortType* Field::getSort() { return sort; }

std::string Field::getName() { return name; }

void Field::show() {
  cout << "(" << name << ", ";
  for(int i = 0; i < sort->getArity(); i++) {
    cout << sort->getSubType(i);
      cout << (i == sort->getArity() - 1 ? ")" : " ");
  }
  cout << endl;
}