/**
 * @file Cat.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat: copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << "Cat: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
  }
  return *this;
}

Cat::~Cat() { std::cout << "Cat: destructor called" << std::endl; }

void Cat::makeSound(void) const {
  std::cout << BLUE << "Meow-meow-meow" << RESET << std::endl;
}