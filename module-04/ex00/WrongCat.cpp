/**
 * @file WrongCat.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  std::cout << "WrongCat: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat: destructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
  std::cout << WRED << "WrongMeow-WrongMeow-WrongMeow" << WRESET << std::endl;
}