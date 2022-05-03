#include "component/Field.h"

Field::Field(std::string name, SortType* sort)
  : name(name), sort(sort) {}

SortType* Field::getSort() { return sort; }

std::string Field::getName() { return name; }