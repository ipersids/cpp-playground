/**
 * @file Dog.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef DOG_EX01_HPP_
#define DOG_EX01_HPP_

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);
  Dog& operator=(const Dog& other);
  ~Dog() override;

  void makeSound(void) const override;
  void setIdea(int i, std::string str);
  const std::string& getIdea(int i) const;

 private:
  Brain* _brain;
};

#endif  // DOG_EX01_HPP_