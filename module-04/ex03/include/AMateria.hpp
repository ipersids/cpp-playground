/**
 * @file AMateria.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef AMATERIA_EX03_HPP_
#define AMATERIA_EX03_HPP_

#include <iostream>

#include "ICharacter.hpp"

class AMateria {
 public:
  AMateria() = delete;
  AMateria(std::string const& type);
  AMateria(const AMateria& other) = delete;
  AMateria& operator=(const AMateria& other) = delete;
  virtual ~AMateria();

  std::string const& getType() const;
  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);

 protected:
  std::string _type;
};

#endif  // AMATERIA_EX03_HPP_