/**
 * @file zombieHorde.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
  try {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
      horde[i].setName(name);
    }
    return horde;
  } catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	  return nullptr;
  }
}