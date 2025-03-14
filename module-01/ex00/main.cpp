/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include <iostream>

#include "Zombie.hpp"

#ifndef COLORS
#define COLORS
#define BLUE "\033[34m"
#define BOLDGREEN "\033[1m\033[32m"
#define RESET "\033[0m"
#endif  // COLORS

int main(void) {
  std::cout << BOLDGREEN << "------ Test ex00 ------\n" << RESET << std::endl;

  std::cout << BLUE << "Testing constructor and destructor (stack):" << RESET
            << std::endl;
  {
    Zombie zoe("Zoe");
    zoe.announce();
  }
  std::cout << "\n" << std::endl;

  std::cout << BLUE << "Testing randomChump() function (stack):" << RESET
            << std::endl;
  { randomChump("Zorrre"); }
  std::cout << "\n" << std::endl;

  std::cout << BLUE
            << "Testing newZombie() function (heap, raw pointer):" << RESET
            << std::endl;
  {
    Zombie* zabre = newZombie("Zabre");
    if (!zabre) {
      return 1;
    }
    zabre->announce();
    delete zabre;
  }
  std::cout << std::endl;

  std::cout << BOLDGREEN << "------ Happy End ------" << RESET << std::endl;
}