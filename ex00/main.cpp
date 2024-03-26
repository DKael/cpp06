#include <iostream>
#include <string>
#include <typeinfo>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Invalid input number!\n";
    return 1;
  }
  ScalarConverter::convert(argv[1]);
}
