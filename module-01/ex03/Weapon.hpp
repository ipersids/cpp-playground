/**
 * @file Weapon.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef WEAPON_EX03_HPP_
#define WEAPON_EX03_HPP_

#include <iostream>

class Weapon {
 public:
  Weapon() = delete;
  Weapon(const std::string& type);
  Weapon(const Weapon& other);
  Weapon& operator=(const Weapon& other);
  ~Weapon();

  const std::string& getType(void) const;
  void setType(const std::string& type);

 private:
  std::string _type;
};

#endif  // WEAPON_EX03_HPP_