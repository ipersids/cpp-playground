#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  _health = 100;
  _energy = 50;
  _damage = 20;

  std::cout << BOLDBLUE << "ScavTrap " << RESET << "(" << _name
            << ") default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _health = 100;
  _energy = 50;
  _damage = 20;

  std::cout << BOLDBLUE << "ScavTrap " << RESET << "(" << _name
            << ") parameterized constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDBLUE << "ScavTrap " << RESET << "(" << _name
            << ") copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDBLUE << "ScavTrap " << RESET << "(" << _name
            << ") assignment operator called." << std::endl;

  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << BOLDBLUE << "ScavTrap " << RESET << "(" << _name
            << ") destructor called." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (_energy == 0) {
    std::cout << "ScavTrap " << BLUE << "(" << _name << ") " << RESET
              << "can't attack. There'is no energy anymore." << std::endl;
    return;
  }
  std::cout << "ScavTrap " << BLUE << "(" << _name << ") " << RESET
            << "attacks " << target << ", causing " << _damage
            << " points of damage!" << std::endl;
  _energy--;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << BLUE << "(" << _name << ") " << RESET
            << "  in Gate keeper mode now." << std::endl;
}