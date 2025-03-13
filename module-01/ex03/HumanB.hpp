/**
 * @file HumanB.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef HUMANB_EX03_HPP_
#define HUMANB_EX03_HPP_

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 public:
  HumanB() = delete;
  HumanB(const std::string& name);
  HumanB(const HumanB& other) = delete;
  HumanB& operator=(const HumanB& other) = delete;
  ~HumanB();

  void attack(void);
  void setWeapon(Weapon& weapon);

 private:
  std::string _name;
  Weapon* _weapon;
};

#endif  // HUMANB_EX03_HPP_