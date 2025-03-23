/**
 * @file Dog.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
  std::cout << "Dog: default constructor called" << std::endl;
  try {
    _brain = new Brain();
  } catch (const std::bad_alloc& e) {
    std::cerr << "Dog brain memory allocation failed: " << e.what()
              << std::endl;
    _brain = nullptr;
  }
}

Dog::Dog(const Dog& other) : AAnimal(other) {
  std::cout << "Dog: copy constructor called" << std::endl;
  try {
    _brain = new Brain(*other._brain);
  } catch (const std::bad_alloc& e) {
    std::cerr << "Dog brain memory allocation failed: " << e.what()
              << std::endl;
    _brain = nullptr;
  }
}

Dog& Dog::operator=(const Dog& other) {
  std::cout << "Dog: copy assignment operator called" << std::endl;
  if (this != &other) {
    _type = other._type;
    try {
      if (_brain) {
        delete _brain;
      }
      _brain = new Brain(*other._brain);
    } catch (const std::bad_alloc& e) {
      std::cerr << "Dog brain memory allocation failed: " << e.what()
                << std::endl;
      _brain = nullptr;
    }
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "Dog: destructor called" << std::endl;
  if (_brain) {
    delete _brain;
  }
}

void Dog::makeSound(void) const {
  std::cout << BLUE << "Woof-woof-woof" << RESET << std::endl;
}

void Dog::setIdea(int i, std::string str) {
  std::cout << "Dog: just get a new idea." << std::endl;
  _brain->setIdea(i, str);
}

const std::string& Dog::getIdea(int i) const { return _brain->getIdea(i); }