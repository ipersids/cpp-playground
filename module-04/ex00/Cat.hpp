/**
 * @file Cat.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef CAT_EX00_HPP_
#define CAT_EX00_HPP_

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  void makeSound(void) const override;
};

#endif  // CAT_EX00_HPP_