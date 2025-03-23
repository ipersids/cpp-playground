/**
 * @file IMateriaSource.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-23
 */

#ifndef IMATERIASOURCE_EX03_HPP_
#define IMATERIASOURCE_EX03_HPP_

#include "AMateria.hpp"

class IMateriaSource {
 public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria* m) = 0;
  virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif  // IMATERIASOURCE_EX03_HPP_