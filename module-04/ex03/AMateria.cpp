/**
 * @file AMateria.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {
  // std::cout << "AMateria: parametrized constructor called" << std::endl;
}

std::string const& AMateria::getType() const { return _type; }

AMateria::~AMateria() {
  // std::cout << "AMateria: destructor called" << std::endl;
}

void AMateria::use(ICharacter& target) {
  std::cout << "* default use of AMateria at " << target.getName() << " *"
            << std::endl;
}