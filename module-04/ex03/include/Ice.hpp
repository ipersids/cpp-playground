/**
 * @file Ice.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef ICE_EX03_HPP_
#define ICE_EX03_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  Ice();
  Ice(const Ice& other) = delete;
  Ice& operator=(const Ice& other) = delete;
  ~Ice() override;

  AMateria* clone() const override;
  void use(ICharacter& target) override;
};

#endif  // ICE_EX03_HPP_