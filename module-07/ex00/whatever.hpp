/**
 * @file whatever.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef WHATEVER_EX00_HPP_
#define WHATEVER_EX00_HPP_

template <typename T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <typename T>
T min(T a, T b) {
  return (b <= a) ? b : a;
}

template <typename T>
T max(T a, T b) {
  return (b >= a) ? b : a;
}

#endif  // WHATEVER_EX00_HPP_