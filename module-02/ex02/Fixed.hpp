/**
 * @file Fixed.hpp
 * @author Julia Persidskaia
 * @date 2025-03-16
*/

#ifndef FIXED_EX00_HPP_
#define FIXED_EX00_HPP_

#include <iostream>
#include <cmath>

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

    Fixed& operator++(); // prefix increment
    Fixed& operator--(); // prefix decrement
    Fixed operator++(int); // postfix increment
    Fixed operator--(int); // postfix decrement

    Fixed operator-(const Fixed& other) const;
    Fixed operator+(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    static Fixed& min(Fixed& lf, Fixed& rf);
    static const Fixed& min(const Fixed& lf, const Fixed& rf);
    static Fixed& max(Fixed& lf, Fixed& rf);
    static const Fixed& max(const Fixed& lf, const Fixed& rf);

  private:
    int _number;
    static const int _point = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

bool operator==(const Fixed& lf, const Fixed& rf);
bool operator!=(const Fixed& lf, const Fixed& rf);
bool operator<(const Fixed& lf, const Fixed& rf);
bool operator>(const Fixed& lf, const Fixed& rf);
bool operator<=(const Fixed& lf, const Fixed& rf);
bool operator>=(const Fixed& lf, const Fixed& rf);

#endif // FIXED_EX00_HPP_