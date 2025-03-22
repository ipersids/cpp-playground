/**
 * @file Animal.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef ANIMAL_EX00_HPP_
#define ANIMAL_EX00_HPP_

#include <iostream>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#endif  // COLORS

class Animal {
 public:
  Animal();
  Animal(std::string type);
  Animal(const Animal& other);
  Animal& operator=(const Animal& other);
  virtual ~Animal();

  virtual void makeSound(void) const;

  std::string getType(void) const;

 protected:
  std::string _type;
};

#endif  // ANIMAL_EX00_HPP_