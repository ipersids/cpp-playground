/**
 * @file Fixed.hpp
 * @author Julia Persidskaia
 * @date 2025-03-16
 */

#ifndef FIXED_EX00_HPP_
#define FIXED_EX00_HPP_

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int _number;
  static const int _point = 8;
};

#endif  // FIXED_EX00_HPP_