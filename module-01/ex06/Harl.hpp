/**
 * @file Harl.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef HARL_EX05_HPP_
#define HARL_EX05_HPP_

#include <iostream>

#define TYPE_COUNT 4

class Harl {
 public:
  Harl();
  Harl(const Harl& other) = delete;
  Harl& operator=(const Harl& other) = delete;
  ~Harl() = default;

  void complain(std::string level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void (Harl::*_complaints[TYPE_COUNT])();
  std::string _types[TYPE_COUNT];
};

#endif  // HARL_EX05_HPP_