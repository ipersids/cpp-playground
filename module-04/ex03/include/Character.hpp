/**
 * @file Character.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef CHARACTER_EX03_HPP_
#define CHARACTER_EX03_HPP_

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

#define SLOTS 4

class Character : public ICharacter {
 public:
  Character(std::string name);
  Character(const Character& other);
  Character& operator=(const Character& other);
  ~Character() override;

  std::string const& getName() const override;
  void equip(AMateria* m) override;
  void unequip(int idx) override;
  void use(int idx, ICharacter& target) override;

 private:
  std::string _name;
  int _free_slots;
  AMateria* _inventory[SLOTS];
  Character() = default;
  void clearInventory(void);
};

#endif  // CHARACTER_EX03_HPP_