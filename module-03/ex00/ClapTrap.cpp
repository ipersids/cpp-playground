#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
  _name = "Uknown";
  _health = 10;
  _energy = 10;
  _damage = 0;

  std::cout << BOLDGREEN << "ClapTrap " << RESET << "(" << _name
            << ") default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name) {
  _health = 10;
  _energy = 10;
  _damage = 0;

  std::cout << BOLDGREEN << "ClapTrap " << RESET << "(" << _name
            << ") parameterized constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDGREEN << "ClapTrap " << RESET << "(" << _name
            << ") copy constructor called." << std::endl;
}

// Assignment operator overload
ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
  if (this != &obj) {
    this->_name = obj._name;
    this->_health = obj._health;
    this->_energy = obj._energy;
    this->_damage = obj._damage;
  }

  std::cout << BOLDGREEN << "ClapTrap " << RESET << "(" << _name
            << ") assignment operator called." << std::endl;

  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << BOLDGREEN << "ClapTrap " << RESET << "(" << _name
            << ") destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (_energy == 0) {
    std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
              << "can't attack. There'is no energy anymore." << std::endl;
    return;
  }
  std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
            << "attacks " << target << ", causing " << _damage
            << " points of damage!" << std::endl;
  _energy--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_health == 0) {
    std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
              << "is already dead. :(" << std::endl;
    return;
  }
  _health = _health - amount;
  std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET << "took "
            << amount << " points of damage. ";
  if (_health <= 0) {
    _health = 0;
    std::cout << "It's dead. :(" << std::endl;
    return;
  }
  std::cout << "Current health level: " << _health << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energy <= 0 && _health > 0) {
    std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
              << "don't have energy to repair itself." << std::endl;
  } else if (_health <= 0) {
    std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
              << "dead things can't repair themselves." << std::endl;
  } else {
    _health += amount;
    _energy--;
    std::cout << "ClapTrap " << GREEN << "(" << _name << ") " << RESET
              << "repaired itself. Current health level: " << _health << "."
              << std::endl;
  }
}
