/**
 * @file newZombie.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
  try {
    Zombie* tmp = new Zombie(name);
    return tmp;
  } catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return nullptr;
  }
}