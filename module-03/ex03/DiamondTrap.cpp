#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
  _name = ClapTrap::_name;
  ClapTrap::_name += "_clap_name";
  ClapTrap::_health = FragTrap::defaultHealth;
  ClapTrap::_energy = ScavTrap::defaultEnergy;
  ClapTrap::_damage = FragTrap::defaultDamage;

  std::cout << BOLDRED << "DiamondTrap " << RESET << "(" << _name
            << ") default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name + "_clap_name"),
      FragTrap(name + "_clap_name") {
  _name = name;
  ClapTrap::_health = FragTrap::defaultHealth;
  ClapTrap::_energy = ScavTrap::defaultEnergy;
  ClapTrap::_damage = FragTrap::defaultDamage;

  std::cout << BOLDRED << "DiamondTrap " << RESET << "(" << _name
            << ") parameterized constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDRED << "DiamondTrap " << RESET << "(" << _name
            << ") copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDRED << "DiamondTrap " << RESET << "(" << _name
            << ") assignment operator called." << std::endl;

  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << BOLDRED << "DiamondTrap " << RESET << "(" << _name
            << ") destructor called." << std::endl;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap ";
  if (_health > 0) {
    std::cout << "My DiamondTrap name is " << RED << _name << RESET
              << ". My ClapTrap name is " << GREEN << ClapTrap::_name << RESET
              << ". Who are you?" << std::endl;
  } else {
    std::cout << ": dead things can't speak. :(" << std::endl;
  }
}