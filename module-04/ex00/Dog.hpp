/**
 * @file Dog.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef DOG_EX00_HPP_
#define DOG_EX00_HPP_

#include <iostream>

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog() override;

  void makeSound(void) const override;
};

#endif  // DOG_EX00_HPP_