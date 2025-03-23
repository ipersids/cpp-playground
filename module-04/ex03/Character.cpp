/**
 * @file Character.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include "Character.hpp"

Character::Character(std::string name) {
  _name = name;
  _free_slots = SLOTS;

  for (int i = 0; i < SLOTS; i++) {
    _inventory[i] = nullptr;
  }

  std::cout << "Character " << _name << ": parametrized constructor called"
            << std::endl;
}

Character::Character(const Character& other) {
  std::cout << "Character " << other._name << ": copy constructor called"
            << std::endl;

  this->clearInventory();
  this->_name = other._name;
  this->_free_slots = other._free_slots;

  for (int i = 0; i < SLOTS; i++) {
    if (other._inventory[i] != nullptr) {
      this->_inventory[i] = other._inventory[i]->clone();
    } else {
      this->_inventory[i] = nullptr;
    }
  }
}

Character& Character::operator=(const Character& other) {
  std::cout << "Character " << this->_name
            << ": copy assignment constructor called" << std::endl;

  if (this == &other) {
    return *this;
  }

  this->clearInventory();
  this->_name = other._name;
  this->_free_slots = other._free_slots;

  for (int i = 0; i < SLOTS; i++) {
    if (other._inventory[i] != nullptr) {
      this->_inventory[i] = other._inventory[i]->clone();
    } else {
      this->_inventory[i] = nullptr;
    }
  }

  return *this;
}

Character::~Character() {
  std::cout << "Character " << this->_name << ": destructor called"
            << std::endl;
  this->clearInventory();
}

std::string const& Character::getName() const { return _name; }

void Character::equip(AMateria* m) {
  if (m == nullptr) {
    std::cout << "Character: equip(): invalid argument (nullptr)" << std::endl;
    return;
  }

  if (_free_slots == 0) {
    std::cout << "Character " << this->getName() << ": inventory is full"
              << std::endl;
    return;
  }
  
  for (int i = 0; i < SLOTS; i++) {
    if (_inventory[i] == nullptr) {
      _inventory[i] = m;
      _free_slots--;
      break;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= SLOTS) {
    std::cout << "Character " << this->getName() << ": index out of boundaries"
              << std::endl;
    return;
  }
  if (_inventory[idx] != nullptr) {
    _inventory[idx] = nullptr;
    _free_slots++;
  }
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx >= SLOTS) {
    std::cout << "Character " << this->getName() << ": index out of boundaries"
              << std::endl;
    return;
  }
  if (_inventory[idx] == nullptr) {
    std::cout << "Character " << this->getName()
              << ": there is no materia to use" << std::endl;
    return;
  }
  _inventory[idx]->use(target);
}

/// Private functions

void Character::clearInventory(void) {
  for (int i = 0; i < SLOTS; i++) {
    if (_inventory[i] != nullptr) {
      delete _inventory[i];
      _inventory[i] = nullptr;
    }
  }
}