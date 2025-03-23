/**
 * @file Brain.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#ifndef BRAIN_EX01_HPP_
#define BRAIN_EX01_HPP_

#include <iostream>

#define IDEAS_AMOUNT 100

class Brain {
 public:
  Brain();
  Brain(const Brain& other);
  Brain& operator=(const Brain& other);
  ~Brain();

  void setIdea(int i, std::string& str);
  const std::string& getIdea(int i) const;

 private:
  std::string _ideas[IDEAS_AMOUNT];
};

#endif  // BRAIN_EX01_HPP_