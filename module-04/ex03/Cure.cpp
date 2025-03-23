/**
 * @file Cure.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
  std::cout << "Cure: default constructor called" << std::endl;
}

Cure::~Cure() { std::cout << "Cure: destructor called" << std::endl; }

AMateria* Cure::clone() const {
  try {
    return new Cure();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Cure: allocation failed" << std::endl;
    return nullptr;
  }
}

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}