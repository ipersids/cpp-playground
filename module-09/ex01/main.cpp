#include <iostream>

#include "RPN.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << MAGENTA "Usage:"
              << RESET "./RPN <inverted Polish mathematical expression>";
    return 1;
  }
  try {
    RPN rpn(argv[1]);
    int res = rpn.calculate();
    std::cout << res << std::endl;
  } catch (std::exception const& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}