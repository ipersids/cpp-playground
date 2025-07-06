#pragma once

#include <iostream>
#include <regex>
#include <sstream>
#include <stack>
#include <stdexcept>

#define ERR_MSG "\033[31mError: \033[0m"

class RPN {
 public:
  RPN() = delete;
  RPN(const std::string& notation);
  RPN& operator=(const RPN& other) = delete;
  RPN(const RPN& other) = delete;
  ~RPN() = default;

  int calculate(void);

 private:
  const std::string _notation;
  std::stack<int> _stack;

  bool isValidOperand(const std::string& symbol) const;
  bool isValidOperator(const std::string& symbol) const;

  int performOperation(const std::string& symbol);
};
