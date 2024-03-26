#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& oring);
  ScalarConverter& operator=(const ScalarConverter& origin);
  ~ScalarConverter();

 public:
  static void convert(std::string input);
};

#endif