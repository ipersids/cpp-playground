/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include <iostream>

#include "Harl.hpp"

#ifndef COLORS
#define COLORS
#define BOLDGREEN "\033[1m\033[32m"
#define RESET "\033[0m"
#endif  // COLORS

int main(void) {
  Harl harl;
  std::cout << BOLDGREEN << "\n----- Test \"DEBUG\" -----" << RESET
            << std::endl;
  harl.complain("DEBUG");
  std::cout << BOLDGREEN << "\n----- Test \"INFO\" -----" << RESET << std::endl;
  harl.complain("INFO");
  std::cout << BOLDGREEN << "\n----- Test \"WARNING\" -----" << RESET
            << std::endl;
  harl.complain("WARNING");
  std::cout << BOLDGREEN << "\n----- Test \"ERROR\" -----" << RESET
            << std::endl;
  harl.complain("ERROR");
  std::cout << BOLDGREEN << "\n----- Test \"UKNOWN\" -----" << RESET
            << std::endl;
  harl.complain("UKNOWN");
  std::cout << std::endl;
  return 0;
}