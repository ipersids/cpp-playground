/**
 * @file WrongAnimal.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef WRONG_ANIMAL_EX00_HPP_
#define WRONG_ANIMAL_EX00_HPP_

#include <iostream>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(std::string type);
  WrongAnimal(const WrongAnimal& other);
  WrongAnimal& operator=(const WrongAnimal& other);
  ~WrongAnimal();

  void makeSound(void) const;

  std::string getType(void) const;

 protected:
  std::string _type;
};

#endif  // WRONG_ANIMAL_EX00_HPP_