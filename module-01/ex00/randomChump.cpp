/**
 * @file randomChump.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Zombie.hpp"

void randomChump(std::string name) {
  Zombie temporary(name);
  temporary.announce();
}