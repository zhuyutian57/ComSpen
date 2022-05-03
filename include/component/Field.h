#if !defined(FIELD_)
#define FIELD_

#include "SortType.h"
#include "Types.h"

class Field {

public:
  Field(std::string name, SortType* sort);
  ~Field() {}

  SortType* getSort();
  std::string getName();

private:
  std::string name;
  SortType* sort;
};

#endif
