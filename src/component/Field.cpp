#include "component/Field.h"

Field::Field(std::string name, std::string sort)
  : name(name), sort(sort) {}


std::string Field::getSort() { return sort; }

std::string Field::getName() { return name; }