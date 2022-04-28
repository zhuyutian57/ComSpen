#if !defined(FIELD_)
#define FIELD_

#include "Types.h"

class Field {

public:
  Field(std::string name, std::string sort);
  ~Field() {}

  std::string getSort();
  std::string getName();

private:
  std::string name;
  std::string sort;

};

#endif
