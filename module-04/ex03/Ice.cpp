/**
 * @file Ice.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice: default constructor called" << std::endl;
}

Ice::~Ice() { std::cout << "Ice: destructor called" << std::endl; }

AMateria* Ice::clone() const {
  try {
    return new Ice();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Ice: allocation failed" << std::endl;
    return nullptr;
  }
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}