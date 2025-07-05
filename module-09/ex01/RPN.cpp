#include "RPN.hpp"

RPN::RPN(const std::string& notation) : _notation(notation), _stack() {}

int RPN::calculate(void) {
  std::istringstream oss(_notation);
  std::string symbol;
  int operand = 0;
  while (oss >> symbol) {
    if (isValidOperand(symbol)) {
      // std::cout << "Operand: " << symbol << std::endl;
      operand = std::stoi(symbol);  // main catch throwed errors
      _stack.push(operand);
      continue;
    }

    if (isValidOperator(symbol)) {
      // std::cout << "Operator: " << symbol << std::endl;
      operand = performOperation(symbol);
      _stack.push(operand);
      continue;
    }

    throw std::invalid_argument(ERR_MSG "Invalid symbol: " + symbol);
  }

  if (_stack.size() != 1) {
    throw std::length_error(ERR_MSG "Too many operands left: " +
                            std::to_string(_stack.size()));
  }

  int result = _stack.top();
  _stack.pop();

  return result;
}

int RPN::performOperation(const std::string& symbol) {
  if (_stack.size() < 2) {
    throw std::length_error(ERR_MSG "Invalid operation: Not enough operands");
  }
  int right = _stack.top();  // reverse order
  _stack.pop();
  int left = _stack.top();
  _stack.pop();

  long int result = 0;
  if (symbol == "+") {
    result = static_cast<long>(left) + right;
  } else if (symbol == "-") {
    result = static_cast<long>(left) - right;
  } else if (symbol == "*") {
    result = static_cast<long>(left) * right;
  } else if (symbol == "/") {
    if (right == 0) {
      throw std::domain_error(ERR_MSG "Division by zero");
    }
    result = static_cast<long>(left) / right;
  } else {
    throw std::invalid_argument(ERR_MSG "Invalid operator: " + symbol);
  }

  if (result < std::numeric_limits<int>::min() ||
      result > std::numeric_limits<int>::max())
    throw std::out_of_range(ERR_MSG "Out of range: Integer overflow");

  return static_cast<int>(result);
}

bool RPN::isValidOperand(const std::string& symbol) const {
  std::regex re(R"(^[0-9]$)");
  return std::regex_match(symbol, re);
}

bool RPN::isValidOperator(const std::string& symbol) const {
  std::regex re(R"(^[+\-*/]$)");
  return std::regex_match(symbol, re);
}
