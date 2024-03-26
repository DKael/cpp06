#include <iostream>
#include <string>
#include <typeinfo>

#include "ScalarConverter.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Invalid input number!\n";
    return 1;
  }
  //   std::string test = "test";
  //   char test_c;
  //   test_c = 'c';

  //   std::cout << typeid(test[0]).name() << ' '
  //             << typeid(static_cast<char>(test[0])).name() << ' ';
  //   std::cout << typeid(test_c).name();
  // ScalarConverter::convert(" ");
  // ScalarConverter::convert("w");
  // ScalarConverter::convert("W");
  // ScalarConverter::convert("!");
  // ScalarConverter::convert("~");
  // ScalarConverter::convert("3");

  for (int i = 0; i < argc; i++) {
    std::cout << '_' << argv[i] << '_' << '\n';
  }

  ScalarConverter::convert(argv[1]);

  float test = 2147483647.0f;

  std::cout << test << '\n';
}
