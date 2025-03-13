/**
 * @file HumanB.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : _name(name) {
  _weapon = nullptr;
  std::cout << "HumanB " << _name << " was created" << std::endl;
}

HumanB::~HumanB() {
  std::cout << "HumanB " << _name << " was destroyed" << std::endl;
}

void HumanB::attack(void) {
  if (_weapon) {
    std::cout << _name << " attacks with their " << _weapon->getType()
              << std::endl;
  } else {
    std::cout << _name << " cannot attack without a weapon" << std::endl;
  }
}

void HumanB::setWeapon(Weapon& weapon) { _weapon = &weapon; }