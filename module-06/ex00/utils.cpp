#include "utils.hpp"

bool isChar(const std::string& literal) {
  std::regex re(R"(^.$)");
  return std::regex_match(literal, re) || literal.length() == 1;
}

bool isIntenger(const std::string& literal) {
  std::regex re(R"(^\s*[+-]?[1-9]\d*\s*|\s*0\s*$)");
  return std::regex_match(literal, re);
}

bool isFloat(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?f\s*$)");
  return std::regex_match(literal, re);
}

bool isDouble(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?\s*$)");
  return std::regex_match(literal, re);
}