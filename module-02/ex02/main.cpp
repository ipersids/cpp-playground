/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-03-20
*/

#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << std::endl;
  std::cout << "(a < a): " << ((a < a) ? "True" : "False") << std::endl;
  std::cout << "(a > a): " << ((a > a) ? "True" : "False") << std::endl;
  std::cout << "(a == a): " << ((a == a) ? "True" : "False") << std::endl;
  std::cout << "(a != a): " << ((a != a) ? "True" : "False") << std::endl;
  std::cout << "(a >= a): " << ((a >= a) ? "True" : "False") << std::endl;
  std::cout << "(a <= a): " << ((a <= a) ? "True" : "False") << std::endl;

  std::cout << std::endl;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  std::cout << "b = " << b << std::endl;
  a = Fixed(1);
  std::cout << "a = " << a << std::endl;
  std::cout << b << " + " << a << " = " << b + a << std::endl;
  std::cout << b << " - " << a << " = " << b - a << std::endl;
  std::cout << b << " * " << a << " = " << b * a << std::endl;
  std::cout << b << " / " << a << " = " << b / a << std::endl;
  std::cout << "max: " << Fixed::max(a, b) << std::endl;
  std::cout << "min: " << Fixed::min(a, b) << std::endl;
  return 0;
}