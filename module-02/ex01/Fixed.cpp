/**
 * @file Fixed.cpp
 * @author Julia Persidskaia
 * @date 2025-04-03
 */

#include "Fixed.hpp"

#include <climits>

Fixed::Fixed() : _number(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  long long int tmp = static_cast<long long int>(value) * (1 << _point);
  if (tmp > INT32_MAX || tmp < INT32_MIN) {
    _number = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
  } else {
    _number = static_cast<int>(tmp);
  }
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  long long int tmp = static_cast<long long int>(
      std::round(static_cast<double>(value) * (1 << _point)));
  if (tmp > INT32_MAX || tmp < INT32_MIN) {
    _number = (tmp > INT32_MAX) ? INT32_MAX : INT32_MIN;
  } else {
    _number = static_cast<int>(tmp);
  }
}

Fixed::Fixed(const Fixed& other) : _number(other._number) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _number = other._number;
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _number;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _number = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(_number) / (1 << _point));
}

int Fixed::toInt(void) const { return (_number / (1 << _point)); }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}