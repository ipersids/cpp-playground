#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define BLUE "\033[34m"
#define BOLDBLUE "\033[1m\033[34m"
#define MAGENTA "\033[35m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define RED "\033[31m"
#define BOLDRED "\033[1m\033[31m"
#define RESET "\033[0m"
#endif  // COLORS

class ClapTrap {
 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& obj);
  ClapTrap& operator=(const ClapTrap& obj);
  virtual ~ClapTrap();

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 protected:
  std::string _name;
  int _health;
  int _energy;
  int _damage;
};

#endif  // CLAPTRAP_HPP