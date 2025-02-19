#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define RESET "\033[0m"
#endif  // COLORS

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& obj);
  ClapTrap& operator=(const ClapTrap& obj);
  ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string _name;
  int _health;
  int _energy;
  int _damage;
};

#endif  // CLAPTRAP_HPP