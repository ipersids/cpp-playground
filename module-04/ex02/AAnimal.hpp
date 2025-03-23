/**
 * @file AAnimal.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef AANIMAL_EX01_HPP_
#define AANIMAL_EX01_HPP_

#include <iostream>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#endif  // COLORS

class AAnimal {
 public:
  AAnimal(std::string type);
  AAnimal(const AAnimal& other);
  AAnimal& operator=(const AAnimal& other);
  virtual ~AAnimal();

  virtual void makeSound(void) const = 0;

  std::string getType(void) const;

 protected:
  std::string _type;
  AAnimal();
};

#endif  // AANIMAL_EX01_HPP_