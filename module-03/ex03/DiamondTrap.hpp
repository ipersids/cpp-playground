#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  DiamondTrap();
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& obj);
  DiamondTrap& operator=(const DiamondTrap& obj);
  ~DiamondTrap() override;

  using ScavTrap::attack;
  void whoAmI();

 private:
  std::string _name;
};

#endif  // DIAMONDTRAP_HPP