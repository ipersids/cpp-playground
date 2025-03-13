/**
 * @file HumanA.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef HUMANA_EX03_HPP_
#define HUMANA_EX03_HPP_

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA() = delete;
  HumanA(const std::string& name, Weapon& weapon);
  HumanA(const HumanA& other) = delete;
  HumanA& operator=(const HumanA& other) = delete;
  ~HumanA();

  void attack(void);

 private:
  std::string _name;
  Weapon& _weapon;
};

#endif  // HUMANA_EX03_HPP_