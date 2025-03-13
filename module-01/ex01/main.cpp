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
  std::cout << BOLDGREEN << "------ Test ex01 ------\n" << RESET << std::endl;

  std::cout << BLUE
            << "Testing zombieHorde() function (heap, array of raw pointers):"
            << RESET << std::endl;
  {
    int amount = 5;
    Zombie* horde = zombieHorde(amount, "Zorde");

    for (int i = 0; i < amount; i++) {
      std::cout << "[" << i << "]: ";
      horde[i].announce();
    }

    delete[] horde;
  }
  std::cout << std::endl;

  std::cout << BOLDGREEN << "------ Happy End ------" << RESET << std::endl;
}