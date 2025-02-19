#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  _health = 100;
  _energy = 100;
  _damage = 30;

  std::cout << BOLDMAGENTA << "FragTrap " << RESET << "(" << _name
            << ") default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _health = 100;
  _energy = 100;
  _damage = 30;

  std::cout << BOLDMAGENTA << "FragTrap " << RESET << "(" << _name
            << ") parameterized constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDMAGENTA << "FragTrap " << RESET << "(" << _name
            << ") copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
  this->_name = obj._name;
  this->_health = obj._health;
  this->_energy = obj._energy;
  this->_damage = obj._damage;

  std::cout << BOLDMAGENTA << "FragTrap " << RESET << "(" << _name
            << ") assignment operator called." << std::endl;

  return *this;
}

FragTrap::~FragTrap() {
  std::cout << BOLDMAGENTA << "FragTrap " << RESET << "(" << _name
            << ") destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << MAGENTA << "(" << _name << ")" << RESET;
  if (_health > 0) {
    std::cout << ": 'It was cool! Give me a high five! ;)'" << std::endl;
  } else {
    std::cout << " dead things can't speak. :(" << std::endl;
  }
}