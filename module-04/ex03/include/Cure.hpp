/**
 * @file Cure.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef CURE_EX03_HPP_
#define CURE_EX03_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  Cure();
  Cure(const Cure& other) = delete;
  Cure& operator=(const Cure& other) = delete;
  ~Cure() override;

  AMateria* clone() const override;
  void use(ICharacter& target) override;
};

#endif  // CURE_EX03_HPP_