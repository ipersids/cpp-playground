/**
 * @file newZombie.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) { return new Zombie(name); }