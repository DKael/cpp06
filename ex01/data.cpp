#include "data.hpp"

Data::Data() : iVal(10), fVal(1.25f), dVal(3.33), sVal("test") { ; }

Data::Data(const Data& origin)
    : iVal(origin.iVal),
      fVal(origin.fVal),
      dVal(origin.dVal),
      sVal(origin.sVal) {
  ;
}

Data& Data::operator=(const Data& origin) {
  iVal = origin.iVal;
  fVal = origin.fVal;
  dVal = origin.dVal;
  sVal = origin.sVal;
  return *this;
}

Data::~Data() { ; }
