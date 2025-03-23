/**
 * @file Animal.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
  std::cout << "AAnimal: default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
  std::cout << "AAnimal: parametrized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : _type(other._type) {
  std::cout << "AAnimal: copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
  std::cout << "AAnimal: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

AAnimal::~AAnimal() { std::cout << "AAnimal: destructor called" << std::endl; }

std::string AAnimal::getType(void) const { return _type; }
