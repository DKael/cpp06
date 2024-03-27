#include "ScalarConverter.hpp"

bool isInt(const std::string& input);
bool isFloat(const std::string& input);
bool isDouble(const std::string& input);
void print4Types(const std::string& c_str, const std::string& i_str,
                 const std::string& f_str, const std::string& d_str);
bool isDiplayable(const char val);
std::string itos(const int val);
std::string ftos(const float val);
std::string dtos(const double val);
std::string trim(const std::string& str);
std::string trimZero(const std::string& str);

void ScalarConverter::convert(std::string input) {
  char cType;
  int iType;
  float fType;
  double dType;
  std::string cStr;
  std::string iStr;
  std::string fStr;
  std::string dStr;
  std::stringstream sBuf;
  int inputLen = input.length();

  if (inputLen == 0) {
    std::cout << "Input string's length is 0!\n";
    return;
  } else if (inputLen == 1 && input.at(0) == ' ') {
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

  if (trimmed.length() == 1 &&
      ((32 <= trimmed.at(0) && trimmed.at(0) <= 47) ||
       (58 <= trimmed.at(0) && trimmed.at(0) <= 126))) {
    // case char
    cType = trimmed.at(0);
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
      return;
    } else {
      // conversion int to char
      cType = static_cast<char>(iType);
      if (isDiplayable(cType) == false) {
        // char is not displayalbe
        if (static_cast<int>(cType) != iType) {
          // overflow at int to char cast
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string("', impossible");
        } else {
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string(1, '\'');
        }
        cStr = cStr + std::string(", Non displayble");
      } else {
        if (static_cast<int>(cType) != iType) {
          // overflow at int to char cast
          cStr = std::string(1, cType) + std::string(", impossible");
        } else {
          cStr = std::string(1, cType);
        }
      }
      // conversion int to float
      fType = static_cast<float>(iType);
      if (static_cast<int>(fType) != iType) {
        // overflow at int to float cast
        fStr = ftos(fType) + std::string(", impossible");
      } else {
        fStr = ftos(fType);
      }
      // conversion int to double
      dType = static_cast<double>(iType);
      if (static_cast<int>(dType) != iType) {
        // overflow at int to double cast
        dStr = dtos(dType) + std::string(", impossible");
      } else {
        dStr = dtos(dType);
      }
      print4Types(cStr, itos(iType), fStr, dStr);
      return;
    }
  } else if (isFloat(trimmed) == true) {
    // case float
    if (trimmed.at(0) == '.') {
      trimmed.insert(0, "0");
    } else if (((trimmed.at(0) == '+' || trimmed.at(0) == '-') &&
                trimmed.at(1) == '.')) {
      trimmed.insert(1, "0");
    }
    trimmed.erase(trimmed.length() - 1, 1);
    if (trimmed.at(trimmed.length() - 1) == '.') {
      trimmed.push_back('0');
    }
    sBuf << trimmed;
    sBuf >> fType;
    if (sBuf.fail()) {
      print4Types(std::string("impossible"), std::string("impossible"),
                  std::string("impossible(overflow)"),
                  std::string("impossible"));
      return;
    } else {
      std::string compare;

      compare = ftos(fType);
      if (trimmed + std::string(1, 'f') != compare) {
        std::cout << "Because of precision, rounding rule is automatically "
                     "applyed to input value!\n";
        std::cout << "oringin value : \t" << trimmed << '\n';
        std::cout << "converted value : \t" << compare << '\n';
        std::cout
            << "---------------------------------------------------------"
               "---------------------------------------------------------\n";
      }
      float div = 0.0;
      float mod = 0.0;

      mod = std::modf(fType, &div);
      // conversion float to char
      cType = static_cast<char>(fType);
      if (isDiplayable(cType) == false) {
        // char is not displayalbe
        if (static_cast<float>(cType) != div) {
          // overflow at float to char cast
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string("', impossible");
        } else if (mod != 0.0) {
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string("', truncated");
        } else {
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string(1, '\'');
        }
        cStr = cStr + std::string(", Non displayble");
      } else {
        if (static_cast<float>(cType) != div) {
          // overflow at float to char cast
          cStr = std::string(1, cType) + std::string(", impossible");
        } else if (mod != 0.0) {
          cStr = std::string(1, cType) + std::string(", truncated");
        } else {
          cStr = std::string(1, cType);
        }
      }
      // conversion float to int
      iType = static_cast<int>(fType);
      if (static_cast<float>(iType) != div) {
        // overflow at float to int cast
        iStr = itos(iType) + std::string(", impossible");
      } else if (mod != 0.0) {
        iStr = itos(iType) + std::string(", truncated");
      } else {
        iStr = itos(iType);
      }
      // conversion float to double
      dType = static_cast<double>(fType);
      if (static_cast<float>(dType) != fType) {
        // overflow at float to double cast
        dStr = dtos(dType) + std::string(", impossible");
      } else {
        dStr = dtos(dType);
      }
      print4Types(cStr, iStr, compare, dStr);
      return;
    }
  } else if (isDouble(trimmed) == true) {
    // case double
    if (trimmed.at(0) == '.') {
      trimmed.insert(0, "0");
    } else if (((trimmed.at(0) == '+' || trimmed.at(0) == '-') &&
                trimmed.at(1) == '.')) {
      trimmed.insert(1, "0");
    }
    if (trimmed.at(trimmed.length() - 1) == '.') {
      trimmed.push_back('0');
    }
    sBuf << trimmed;
    sBuf >> dType;
    if (sBuf.fail()) {
      print4Types(std::string("impossible"), std::string("impossible"),
                  std::string("impossible"),
                  std::string("impossible(overflow)"));
      return;
    } else {
      std::string compare;

      compare = dtos(dType);
      if (trimmed != compare) {
        std::cout << "Because of precision, rounding rule is automatically "
                     "applyed to input value!\n";
        std::cout << "oringin value : \t" << trimmed << '\n';
        std::cout << "converted value : \t" << compare << '\n';
        std::cout
            << "---------------------------------------------------------"
               "---------------------------------------------------------\n";
      }
      double div = 0.0;
      double mod = 0.0;

      mod = std::modf(dType, &div);
      // conversion double to char
      cType = static_cast<char>(dType);
      if (isDiplayable(cType) == false) {
        // char is not displayable
        if (static_cast<double>(cType) != div) {
          // overflow at double to char cast
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string("', impossible");
        } else if (mod != 0.0) {
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string("', truncated");
        } else {
          cStr = std::string(1, '\'') + itos(static_cast<int>(cType)) +
                 std::string(1, '\'');
        }
        cStr = cStr + std::string(", Non displayble");
      } else {
        if (static_cast<double>(cType) != div) {
          // overflow at double to char cast
          cStr = std::string(1, cType) + std::string(", impossible");
        } else if (mod != 0.0) {
          cStr = std::string(1, cType) + std::string(", truncated");
        } else {
          cStr = std::string(1, cType);
        }
      }
      // conversion double to int
      iType = static_cast<int>(dType);
      if (static_cast<double>(iType) != div) {
        // overflow at double to int cast
        iStr = itos(iType) + std::string(", impossible");
      } else if (mod != 0.0) {
        iStr = itos(iType) + std::string(", truncated");
      } else {
        iStr = itos(iType);
      }
      // conversion double to float
      fType = static_cast<float>(dType);
      if (static_cast<double>(fType) != dType) {
        // overflow at double to float cast
        fStr = ftos(fType) + std::string(", impossible");
      } else {
        fStr = ftos(fType);
      }
      print4Types(cStr, iStr, fStr, compare);
      return;
    }
  } else if (trimmed == "inf" || trimmed == "-inf" || trimmed == "+inf") {
    // case double infinity
    if (trimmed.at(0) == '-') {
      dType = -std::numeric_limits<double>::infinity();
    } else {
      dType = std::numeric_limits<double>::infinity();
    }
    cType = static_cast<char>(dType);
    iType = static_cast<int>(dType);
    fType = static_cast<float>(dType);
    std::cout << "char:   " << cType << ", impossible\n"
              << "int:    " << iType << ", impossible\n"
              << "float:  " << fType << "f\n"
              << "double: " << dType << '\n';
    return;
  } else if (trimmed == "nan") {
    // case double not a number
    dType = std::numeric_limits<double>::quiet_NaN();
    cType = static_cast<char>(dType);
    iType = static_cast<int>(dType);
    fType = static_cast<float>(dType);
    std::cout << "char:   " << cType << ", impossible\n"
              << "int:    " << iType << ", impossible\n"
              << "float:  " << fType << "f\n"
              << "double: " << dType << '\n';
    return;
  } else if (trimmed == "inff" || trimmed == "-inff" || trimmed == "+inff") {
    // case float infinity
    if (trimmed.at(0) == '-') {
      fType = -std::numeric_limits<float>::infinity();
    } else {
      fType = std::numeric_limits<float>::infinity();
    }
    cType = static_cast<char>(fType);
    iType = static_cast<int>(fType);
    dType = static_cast<float>(fType);
    std::cout << "char:   " << cType << ", impossible\n"
              << "int:    " << iType << ", impossible\n"
              << "float:  " << fType << "f\n"
              << "double: " << dType << '\n';
    return;
  } else if (trimmed == "nanf") {
    // case float not a number
    fType = std::numeric_limits<float>::quiet_NaN();
    cType = static_cast<char>(fType);
    iType = static_cast<int>(fType);
    dType = static_cast<float>(fType);
    std::cout << "char:   " << cType << ", impossible\n"
              << "int:    " << iType << ", impossible\n"
              << "float:  " << fType << "f\n"
              << "double: " << dType << '\n';
    return;
  } else {
    std::cout << "Input is not a char or a decimal notation!\n";
    return;
  }
}

bool isInt(const std::string& input) {
  size_t startIdx = 0UL;

  if (input.at(0) == '+' || input.at(0) == '-') {
    startIdx++;
  }
  if (input.at(startIdx) == '0' && input.length() > 1UL + startIdx) {
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

  if (input.at(0) == '+' || input.at(0) == '-') {
    startIdx++;
  }
  if (input.at(startIdx) == '0' && startIdx + 1UL < input.length() &&
      input.at(startIdx + 1UL) != '.') {
    return false;
  }
  size_t not_num = input.find_first_not_of("0123456789", startIdx);
  if (not_num == std::string::npos || input.at(not_num) != '.') {
    return false;
  }
  not_num = input.find_first_not_of("0123456789", not_num + 1UL);
  if (not_num == std::string::npos || input.at(not_num) != 'f' ||
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

  if (input.at(0) == '+' || input.at(0) == '-') {
    startIdx++;
  }
  if (input.at(startIdx) == '0' && startIdx + 1UL < input.length() &&
      input.at(startIdx + 1UL) != '.') {
    return false;
  }
  size_t not_num = input.find_first_not_of("0123456789", startIdx);
  if (not_num == std::string::npos || input.at(not_num) != '.') {
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
  std::cout << "char:   " << c_str << '\n'
            << "int:    " << i_str << '\n'
            << "float:  " << f_str << '\n'
            << "double: " << d_str << '\n';
}

bool isDiplayable(const char val) {
  if (32 <= val && val <= 126) {
    return true;
  }
  return false;
}

std::string itos(const int val) {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::string ftos(const float val) {
  std::stringstream ss;
  std::string retVal;
  float div = 0.0f;

  if (std::modff(val, &div) == 0.0f) {
    ss << std::fixed << std::setprecision(1) << val;
  } else {
    ss << std::fixed << std::setprecision(10) << val;
  }
  retVal = trimZero(ss.str());
  if (retVal.at(retVal.length() - 1) == '.') {
    retVal.push_back('0');
  }
  retVal.push_back('f');
  return retVal;
}

std::string dtos(const double val) {
  std::stringstream ss;
  std::string retVal;
  double div = 0.0;

  if (std::modf(val, &div) == 0.0) {
    ss << std::fixed << std::setprecision(1) << val;
  } else {
    ss << std::fixed << std::setprecision(20) << val;
  }
  retVal = trimZero(ss.str());
  if (retVal.at(retVal.length() - 1) == '.') {
    retVal.push_back('0');
  }
  return retVal;
}

std::string trim(const std::string& str) {
  size_t first = str.find_first_not_of(" \t\n\r");
  if (first == std::string::npos) {
    return "";
  };

  size_t last = str.find_last_not_of(" \t\n\r");
  return str.substr(first, last - first + 1);
}

std::string trimZero(const std::string& str) {
  size_t last = str.find_last_not_of("0");
  return str.substr(0, last + 1);
}
