#include "ScalarConverter.hpp"

bool isInt(const std::string& input);
bool isFloat(const std::string& input);
bool isDouble(const std::string& input);
void print4Types(const std::string& c_str, const std::string& i_str,
                 const std::string& f_str, const std::string& d_str);
std::string itos(const int val);
std::string ftos(const float val);
std::string dtos(const double val);
std::string trim(const std::string& str);

void ScalarConverter::convert(std::string input) {
  char cType;
  int iType;
  float fType;
  double dType;
  std::stringstream sBuf;
  int inputLen = input.length();

  if (inputLen == 0) {
    std::cout << "Input string's length is 0!\n";
    return;
  } else if (inputLen == 1 && input[0] == ' ') {
    // case whitespace
    cType = ' ';
    iType = static_cast<int>(cType);
    fType = static_cast<float>(cType);
    dType = static_cast<double>(cType);
    print4Types(std::string(1, cType), itos(iType), ftos(fType), dtos(dType));
    return;
  }

  std::string trimmed = trim(input);

  if (trimmed.length() == 0) {
    std::cout << "Input's contents is all whitespace!\n";
    return;
  }

  if (trimmed.length() == 1 && ((32 <= trimmed[0] && trimmed[0] <= 47) ||
                                (58 <= trimmed[0] && trimmed[0] <= 126))) {
    // case char
    cType = trimmed[0];
    iType = static_cast<int>(cType);
    fType = static_cast<float>(cType);
    dType = static_cast<double>(cType);
    print4Types(std::string(1, cType), itos(iType), ftos(fType), dtos(dType));
  } else if (isInt(trimmed) == true) {
    // case int
    sBuf << trimmed;
    sBuf >> iType;
    if (sBuf.fail()) {
      print4Types(std::string("impossible"),
                  std::string("impossible(overflow)"),
                  std::string("impossible"), std::string("impossible"));
    } else {
      std::cout << "int check\n";
    }
  } else if (isFloat(trimmed) == true) {
    // case float
    if (trimmed[0] == '.') {
      trimmed.insert(0, "0");
    } else if (((trimmed[0] == '+' || trimmed[0] == '-') &&
                trimmed[1] == '.')) {
      trimmed.insert(1, "0");
    }
    sBuf << trimmed;
    sBuf >> iType;
    if (sBuf.fail()) {
      print4Types(std::string("impossible"), std::string("impossible"),
                  std::string("impossible(overflow)"),
                  std::string("impossible"));
    } else {
      std::cout << "float check\n";
    }
  } else if (isDouble(trimmed) == true) {
    // case double
    if (trimmed[0] == '.') {
      trimmed.insert(0, "0");
    } else if (((trimmed[0] == '+' || trimmed[0] == '-') &&
                trimmed[1] == '.')) {
      trimmed.insert(1, "0");
    }
    sBuf << trimmed;
    sBuf >> iType;
    if (sBuf.fail()) {
      print4Types(std::string("impossible"), std::string("impossible"),
                  std::string("impossible"),
                  std::string("impossible(overflow)"));
    } else {
      std::cout << "double check\n";
    }
  } else if (trimmed == "inf" || trimmed == "-inf" || trimmed == "+inf") {
    // case double infinity
  } else if (trimmed == "nan") {
    // case double not a number
  } else if (trimmed == "inff" || trimmed == "-inff" || trimmed == "+inff") {
    // case float infinity
  } else if (trimmed == "nanf") {
    // case float not a number
  } else {
    std::cout << "Input is not a char or a decimal notation!\n";
    return;
  }
}

bool isInt(const std::string& input) {
  size_t startIdx = 0UL;

  if (input[0] == '+' || input[0] == '-') {
    startIdx++;
  }
  if (input[startIdx] == '0' && input.length() > 1UL + startIdx) {
    return false;
  }
  size_t not_num = input.find_first_not_of("0123456789", startIdx);
  if (not_num != std::string::npos) {
    return false;
  }
  return true;
}

bool isFloat(const std::string& input) {
  size_t startIdx = 0UL;

  if (input[0] == '+' || input[0] == '-') {
    startIdx++;
  }
  if (input[startIdx] == '0' && startIdx + 1UL < input.length() &&
      input[startIdx + 1UL] != '.') {
    return false;
  }
  size_t not_num = input.find_first_not_of("0123456789", startIdx);
  if (not_num == std::string::npos || input[not_num] != '.') {
    return false;
  }
  not_num = input.find_first_not_of("0123456789", not_num + 1UL);
  if (not_num == std::string::npos || input[not_num] != 'f' ||
      not_num != input.length() - 1) {
    return false;
  }
  if (input == ".f" || input == "+.f" || input == "-.f") {
    return false;
  }
  return true;
}

bool isDouble(const std::string& input) {
  size_t startIdx = 0UL;

  if (input[0] == '+' || input[0] == '-') {
    startIdx++;
  }
  if (input[startIdx] == '0' && startIdx + 1UL < input.length() &&
      input[startIdx + 1UL] != '.') {
    return false;
  }
  size_t not_num = input.find_first_not_of("0123456789", startIdx);
  if (not_num == std::string::npos || input[not_num] != '.') {
    return false;
  }
  not_num = input.find_first_not_of("0123456789", not_num + 1UL);
  if (not_num != std::string::npos) {
    return false;
  }
  if (input == "." || input == "+." || input == "-.") {
    return false;
  }
  return true;
}

void print4Types(const std::string& c_str, const std::string& i_str,
                 const std::string& f_str, const std::string& d_str) {
  std::cout << "char: " << c_str << '\n' << "int: " << i_str << '\n';
  std::cout.precision(1);
  std::cout << std::fixed << "float: " << f_str;
  if (f_str == "impossible(overflow)" || f_str == "impossible") {
    std::cout << '\n';
  } else {
    std::cout << "f\n";
  }
  std::cout << "double: " << d_str << '\n';
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
