/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-04-03
 */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;                // Default constructor called
  Fixed const b(10);      // Int constructor called
  Fixed const c(42.42f);  // Float constructor called
  Fixed const d(b);       // Copy constructor called

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  std::cout << "OVERFLOW" << std::endl;
  Fixed e(INT32_MAX);
  Fixed g(INT32_MIN);

  std::cout << "e is " << e << std::endl;
  std::cout << "g is " << g << std::endl;

  Fixed i(static_cast<float>(INT32_MAX));
  Fixed j(static_cast<float>(INT32_MIN));

  std::cout << "i is " << i << std::endl;
  std::cout << "j is " << j << std::endl;

  return 0;
}