#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& obj);
  ScavTrap& operator=(const ScavTrap& obj);
  ~ScavTrap() override;

  void attack(const std::string& target) override;
  void guardGate(void);
};

#endif  // SCAVTRAP_HPP