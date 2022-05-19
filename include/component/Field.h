#if !defined(FIELD_)
#define FIELD_

#include "SortType.h"
#include "Types.h"

namespace ComSpen {

class Field {

public:
  Field(std::string name, SortType* sort);
  ~Field() {}

  SortType* getSort();
  std::string getName();
  void show();

private:
  std::string name;
  SortType* sort;
};

}

#endif
