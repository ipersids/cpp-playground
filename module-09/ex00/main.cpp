#include <iostream>

#include "BitcoinExchange.hpp"

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
    std::cerr << MAGENTA "Usage: " << RESET "./btc <input file>" << std::endl;
    return 1;
  }

  (void)argv;
  try {
    BitcoinExchange btc;
    btc.exchange(argv[1]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}