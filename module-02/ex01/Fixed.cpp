/**
 * @file Fixed.cpp
 * @author Julia Persidskaia
 * @date 2025-03-16
*/

#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  std::cout << "Int constructor called" << std::endl;
  _number = value * (1 << _point);
}

Fixed::Fixed(const float value) {
  std::cout << "Float constructor called" << std::endl;
  _number = static_cast<int>(std::round(static_cast<double>(value) * (1 << _point)));
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

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return _number;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _number = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<double>(_number) / (1 << _point));
}

int Fixed::toInt(void) const {
  return (_number / (1 << _point));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}