/**
 * @file HumanA.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
    : _name(name), _weapon(weapon) {
  std::cout << "HumanA " << _name << " was created" << std::endl;
}

HumanA::~HumanA() {
  std::cout << "HumanA " << _name << " was destroyed" << std::endl;
}

void HumanA::attack(void) {
  std::cout << _name << " attacks with their " << _weapon.getType()
            << std::endl;
}