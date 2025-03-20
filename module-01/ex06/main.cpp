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

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./harlFilter <TYPE>" << std::endl;
    return 1;
  }

  Harl harl;
  harl.complain(argv[1]);

  return 0;
}