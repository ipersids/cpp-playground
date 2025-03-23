/**
 * @file MateriaSource.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < M_SLOTS; i++) {
    _inventory[i] = nullptr;
  }
  _index = 0;
  std::cout << "MateriaSource: default constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource: defstructor called" << std::endl;

  for (int i = 0; i < M_SLOTS; i++) {
    if (_inventory[i] != nullptr) {
      delete _inventory[i];
      _inventory[i] = nullptr;
    }
  }
}

void MateriaSource::learnMateria(AMateria* m) {
  if (m == nullptr) {
    std::cout << "MateriaSource: invalid argument (nullptr)" << std::endl;
    return;
  }
  if (_index >= M_SLOTS) {
    std::cout << "MateriaSource: inventory is full" << std::endl;
    return;
  }
  _inventory[_index] = m;
  _index++;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < _index; i++) {
    if (_inventory[i]->getType() == type) {
      return _inventory[i]->clone();
    }
  }
  std::cout << "MateriaSource: materia didn't find" << std::endl;
  return 0;
}