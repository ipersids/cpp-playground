/**
 * @file Animal.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
  std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
  std::cout << "Animal: parametrized constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : _type(other._type) {
  std::cout << "Animal: copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  std::cout << "Animal: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "Animal: destructor called" << std::endl; }

void Animal::makeSound(void) const {}

std::string Animal::getType(void) const { return _type; }
