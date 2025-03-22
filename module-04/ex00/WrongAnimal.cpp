/**
 * @file WrongAnimal.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "WrongAnimal: parametrized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type) {
  std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  std::cout << "WrongAnimal: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal: destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "WrongAnimal made wrong sound." << std::endl;
}

std::string WrongAnimal::getType(void) const { return _type; }