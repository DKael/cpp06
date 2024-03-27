#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& origin);
  ScalarConverter& operator=(const ScalarConverter& origin);
  ~ScalarConverter();

 public:
  static void convert(std::string input);
};

#endif