#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& obj);
  ScavTrap& operator=(const ScavTrap& obj);
  ~ScavTrap() override;

  void attack(const std::string& target) override;
  void guardGate(void);

 protected:
  static const int defaultEnergy = 50;
};

#endif  // SCAVTRAP_HPP