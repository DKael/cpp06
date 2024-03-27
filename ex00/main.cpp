#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Invalid input number!\n";
    return 1;
  }
  try {
    ScalarConverter::convert(argv[1]);
  } catch (std::exception& e) {
    std::cerr << e.what();
  }
}
