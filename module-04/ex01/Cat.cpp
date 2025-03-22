/**
 * @file Cat.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat: default constructor called" << std::endl;
  try {
    _brain = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Cat brain memory allocation failed: " << e.what()
              << std::endl;
    _brain = nullptr;
  }
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat: copy constructor called" << std::endl;
  try {
    _brain = new Brain(*other._brain);
  } catch (const std::bad_alloc& e) {
    std::cerr << "Cat brain memory allocation failed: " << e.what()
              << std::endl;
    _brain = nullptr;
  }
}

Cat& Cat::operator=(const Cat& other) {
  std::cout << "Cat: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
    try {
      if (_brain) {
        delete _brain;
      }
      _brain = new Brain(*other._brain);
    } catch (const std::bad_alloc& e) {
      std::cerr << "Cat brain memory allocation failed: " << e.what()
                << std::endl;
      _brain = nullptr;
    }
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat: destructor called" << std::endl;
  if (_brain) {
    delete _brain;
  }
}

void Cat::makeSound(void) const {
  std::cout << GREEN << "Meow-meow-meow" << RESET << std::endl;
}

void Cat::setIdea(int i, std::string str) {
  std::cout << "Cat: just get a new idea." << std::endl;
  _brain->setIdea(i, str);
}

const std::string& Cat::getIdea(int i) const { return _brain->getIdea(i); }