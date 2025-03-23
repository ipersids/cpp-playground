/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#ifndef COLORS
#define COLORS
#define BLUE "\033[34m"
#define RED "\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define RESET "\033[0m"
#endif  // COLORS

int main(void) {
  std::cout << BOLDGREEN << "------------- CONSTRUCTORS -------------\n"
            << RESET << std::endl;
  std::cout << BLUE
            << "Create 'src' (raw pointer) and add 'ice' (raw pointer) and "
               "'cure' (raw pointer): "
            << RESET << std::endl;
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  // src->learnMateria(nullptr);
  std::cout << BLUE << "Create 'me' (raw pointer): " << RESET << std::endl;
  ICharacter* me = new Character("me");
  std::cout << BLUE << "Create 'bob' (raw pointer):" << RESET << std::endl;
  ICharacter* bob = new Character("bob");

  std::cout << BOLDGREEN << "\n-------- createMateria and equip -------\n"
            << RESET << std::endl;
  AMateria* tmp_ice;
  AMateria* tmp_cure;
  std::cout << BLUE << "Add 'ice' to 'me' (raw pointer): " << RESET
            << std::endl;
  tmp_ice = src->createMateria("ice");
  me->equip(tmp_ice);
  std::cout << BLUE << "Add 'cure' to 'me' (raw pointer): " << RESET
            << std::endl;
  tmp_cure = src->createMateria("cure");
  me->equip(tmp_cure);

  std::cout << BOLDGREEN << "\n-------- Call use() -------\n"
            << RESET << std::endl;
  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(4, *bob);

  std::cout << BOLDGREEN << "\n-------- createMateria and unequip -------\n"
            << RESET << std::endl;
  AMateria* tmp_ice_to_unequip;
  std::cout << BLUE << "Add 'ice' to 'bob' (raw pointer): " << RESET
            << std::endl;
  tmp_ice_to_unequip = src->createMateria("ice");
  bob->equip(tmp_ice_to_unequip);
  // bob->equip(nullptr);
  std::cout
      << BLUE
      << "Unequip 'ice' from 'bob':" <<  RESET << "\n(raw pointer should be deleted separately): "
      << std::endl;
  bob->unequip(0);

  std::cout << BOLDGREEN << "\n-------------- DESTRUCTORS -------------\n"
            << RESET << std::endl;
  std::cout << RED << "Delete 'bob' (1 raw pointer): " << RESET << std::endl;
  delete bob;
  std::cout << RED << "Delete 'me' (1 + 2 raw pointers): " << RESET
            << std::endl;
  delete me;
  std::cout << RED << "Delete 'src' (1 + 2 raw pointers): " << RESET
            << std::endl;
  delete src;
  std::cout << RED << "Delete 'tmp_ice_to_unequip' (1 raw pointer): " << RESET
            << std::endl;
  delete tmp_ice_to_unequip;

  return 0;
}