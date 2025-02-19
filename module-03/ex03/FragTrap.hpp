#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& obj);
  FragTrap& operator=(const FragTrap& obj);
  ~FragTrap() override;

  void highFivesGuys(void);

 protected:
  static const int defaultHealth = 100;
  static const int defaultDamage = 30;
};

#endif  // FRAGTRAP_HPP