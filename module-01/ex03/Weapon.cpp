/**
 * @file Weapon.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {
  std::cout << "Weapon " << _type << " was created" << std::endl;
}

Weapon::Weapon(const Weapon& other) { _type = other._type; }

Weapon& Weapon::operator=(const Weapon& other) {
  this->_type = other._type;
  return *this;
}

Weapon::~Weapon() {
  std::cout << "Weapon " << _type << " was destroyed" << std::endl;
}

const std::string& Weapon::getType(void) const { return _type; }

void Weapon::setType(const std::string& type) { _type = type; }