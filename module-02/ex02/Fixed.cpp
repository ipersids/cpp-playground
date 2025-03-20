/**
 * @file Fixed.cpp
 * @author Julia Persidskaia
 * @date 2025-03-20
*/

#include "Fixed.hpp"

Fixed::Fixed() : _number(0) {
  //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
  //std::cout << "Int constructor called" << std::endl;
  _number = value * (1 << _point);
}

Fixed::Fixed(const float value) {
  //std::cout << "Float constructor called" << std::endl;
  _number = static_cast<int>(std::roundf(static_cast<double>(value) * (1 << _point)));
}

Fixed::Fixed(const Fixed& other) : _number(other._number) {
  //std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  //std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _number = other._number;
  }
  return *this;
}

Fixed::~Fixed() {
  //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  //std::cout << "getRawBits member function called" << std::endl;
  return _number;
}

void Fixed::setRawBits(int const raw) {
  //std::cout << "setRawBits member function called" << std::endl;
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

Fixed& Fixed::operator++() {
  _number = _number + 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed old = *this;
  operator++();
  return old;
}

Fixed& Fixed::operator--() {
  _number = _number - 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed old = *this;
  operator--();
  return old;
}

bool operator==(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() == rf.getRawBits();
}

bool operator!=(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() != rf.getRawBits();
}

bool operator<(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() < rf.getRawBits();
}

bool operator>(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() > rf.getRawBits();
}

bool operator<=(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() <= rf.getRawBits();
}

bool operator>=(const Fixed& lf, const Fixed& rf) {
  return lf.getRawBits() >= rf.getRawBits();
}

Fixed Fixed::operator-(const Fixed& other) const {
  return this->toFloat() - other.toFloat();
}

Fixed Fixed::operator+(const Fixed& other) const {
  return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator*(const Fixed& other) const {
  return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed& other) const {
  return this->toFloat() / other.toFloat();
}

Fixed& Fixed::min(Fixed& lf, Fixed& rf) {
  return (lf < rf) ? lf : rf;
}

const Fixed& Fixed::min(const Fixed& lf, const Fixed& rf) {
  return (lf < rf) ? lf : rf;
}

Fixed& Fixed::max(Fixed& lf, Fixed& rf) {
  return (lf > rf) ? lf : rf;
}

const Fixed& Fixed::max(const Fixed& lf, const Fixed& rf) {
  return (lf > rf) ? lf : rf;
}
