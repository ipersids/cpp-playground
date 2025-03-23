/**
 * @file MateriaSource.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef MATERIASOURCE_EX03_HPP_
#define MATERIASOURCE_EX03_HPP_

#include <iostream>

#include "IMateriaSource.hpp"

#define M_SLOTS 4

class MateriaSource : public IMateriaSource {
 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other) = delete;
  MateriaSource& operator=(const MateriaSource& other) = delete;
  ~MateriaSource() override;

  void learnMateria(AMateria* m) override;
  AMateria* createMateria(std::string const& type) override;

 private:
  AMateria* _inventory[M_SLOTS];
  int _index;
};

#endif  // MATERIASOURCE_EX03_HPP_