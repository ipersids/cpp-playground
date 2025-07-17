#include <iostream>

#include "PmergeMe.hpp"

#ifndef COLORS
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << MAGENTA "Usage: " << RESET
              << "./PmergeMe <a positive integer sequence>" << std::endl;
    return 1;
  }
  PmergeMe(argc - 1, argv + 1);
  return 0;
}
