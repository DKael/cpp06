#include "ScalarConverter.hpp"

bool isdigit(std::string input);
void print4Types(const std::string& c_str, const std::string& i_str,
                 const std::string& f_str, const std::string& d_str);
std::string itos(const int val);
std::string ftos(const float val);
std::string dtos(const double val);
std::string trim(const std::string& str);

void ScalarConverter::convert(std::string input) {
  char c_type;
  int i_type;
  float f_type;
  double d_type;
  int input_len = input.length();

  if (input_len == 0) {
    std::cout << "Input string's length is 0!\n";
    return;
  } else if (input_len == 1 && input[0] == ' ') {
    // case whitespace
    c_type = ' ';
    i_type = static_cast<int>(c_type);
    f_type = static_cast<float>(c_type);
    d_type = static_cast<double>(c_type);
    print4Types(std::string(1, c_type), itos(i_type), ftos(f_type),
                dtos(d_type));
  }

  std::string trimmed = trim(input);

  if (input.length() == 1 && ((32 <= input[0] && input[0] <= 47) ||
                              (58 <= input[0] && input[0] <= 126))) {
    // case char
    c_type = input[0];
    i_type = static_cast<int>(c_type);
    f_type = static_cast<float>(c_type);
    d_type = static_cast<double>(c_type);
    print4Types(std::string(1, c_type), itos(i_type), ftos(f_type),
                dtos(d_type));
  }  // else if (input.length() >= 1) {
  //   if (input.length() >= 1 && (input[0] == '-' || input[]))
  //     size_t not_num = input.find_first_not_of("0123456789");

  //   if (((input.length() >= 1 && input[0] != '0') ||
  //        (input.length() == 1 && input[0] == '0')) &&
  //       not_num == std::string::npos) {
  //     // case int

  //   } else if (input[not_num] == '.') {
  //     size_t not_num1 = input.find_first_not_of("0123456789", not_num + 1UL);
  //   } else {
  //   }
  // }
}

bool isdigit(std::string& input) {}

void print4Types(const std::string& c_str, const std::string& i_str,
                 const std::string& f_str, const std::string& d_str) {
  std::cout << "char: " << c_str << '\n' << "int: " << i_str << '\n';
  std::cout.precision(1);
  std::cout << std::fixed << "float: " << f_str << "f\n"
            << "double: " << d_str << '\n';
}

std::string itos(const int val) {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::string ftos(const float val) {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::string dtos(const double val) {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::string trim(const std::string& str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (first == std::string::npos) {
    return "";
  };

  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, last - first + 1);
}