/**
 * @file Brain.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include "Brain.hpp"

Brain::Brain() {
  std::string some_ideas[3]{"I want sleep.", "I want play.", "I want eat."};

  for (int i = 0; i < IDEAS_AMOUNT; i++) {
    _ideas[i] = some_ideas[i % 3];
  }

  std::cout << "Brain: default constructor called" << std::endl;
}

Brain::~Brain() { std::cout << "Brain: destructor called" << std::endl; }

Brain::Brain(const Brain& other) {
  for (int i = 0; i < IDEAS_AMOUNT; i++) {
    _ideas[i] = other._ideas[i];
  }
  std::cout << "Brain: copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < IDEAS_AMOUNT; i++) {
      _ideas[i] = other._ideas[i];
    }
  }
  std::cout << "Brain: assignment operator called" << std::endl;
  return *this;
}

void Brain::setIdea(int i, std::string& str) {
  if (i >= 0 && i < 100) {
    _ideas[i] = str;
  } else {
    std::cout << "brain: " << i << " is out my capacity" << std::endl;
  }
}

const std::string& Brain::getIdea(int i) const {
  if (i >= 0 && i < 100) {
    return _ideas[i];
  } else {
    static const std::string error = "index is out my brain capacity";
    return error;
  }
}