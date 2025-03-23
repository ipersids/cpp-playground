/**
 * @file Cat.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef CAT_EX01_HPP_
#define CAT_EX01_HPP_

#include <iostream>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
 public:
  Cat();
  Cat(const Cat& other);
  Cat& operator=(const Cat& other);
  ~Cat();

  void makeSound(void) const override;
  void setIdea(int i, std::string str);
  const std::string& getIdea(int i) const;

 private:
  Brain* _brain;
};

#endif  // CAT_EX01_HPP_