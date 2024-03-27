#ifndef DATA_CPP
#define DATA_CPP

#include <string>

struct Data {
  int iVal;
  float fVal;
  double dVal;
  std::string sVal;

  Data();
  Data(const Data& origin);
  Data& operator=(const Data& origin);
  ~Data();
};

#endif