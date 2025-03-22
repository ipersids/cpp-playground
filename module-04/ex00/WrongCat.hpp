/**
 * @file WrongCat.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef WRONG_CAT_EX00_HPP_
#define WRONG_CAT_EX00_HPP_

#include "WrongAnimal.hpp"

#define WRED "\033[31m"
#define WRESET "\033[0m"

#include <iostream>

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& other);
  WrongCat& operator=(const WrongCat& other);
  ~WrongCat();

  void makeSound(void) const;
};

#endif  // WRONG_CAT_EX00_HPP_