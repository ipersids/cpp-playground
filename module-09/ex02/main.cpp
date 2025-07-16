#include <iostream>
#include "PmergeMe.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

int main(int argc, char** argv) {
  (void)argc;
  (void)(argv);
  // if (argc < 2) {
  //   std::cerr << MAGENTA "Usage: " << RESET "./PmergeMe <a positive integer sequence>" << std::endl;
  //   return 1;
  // }
  std::vector<int> v = {5, 2, 8, 1, 9, 3, 7};
  runFordJohnsonAlgorithm(v);
  return 0;
}
