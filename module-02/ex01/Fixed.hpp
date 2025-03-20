/**
 * @file Fixed.hpp
 * @author Julia Persidskaia
 * @date 2025-03-16
 */

#ifndef FIXED_EX00_HPP_
#define FIXED_EX00_HPP_

#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

 private:
  int _number;
  static const int _point = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif  // FIXED_EX00_HPP_