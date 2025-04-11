/**
 * @file Array.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-11
 */

#ifndef ARRAY_EX02_HPP_
#define ARRAY_EX02_HPP_

#include <iostream>

template <typename T>
class Array {
 public:
  Array() : _n(0), _arr(nullptr) {
    // std::cout << "Array: default constructor called" << std::endl;
  }

  Array(unsigned int n) : _n(n) {
    _arr = new (std::nothrow) T[n];
    if (_arr == nullptr) {
      std::cerr << "Error: Array: Memory allocation failed" << std::endl;
      _n = 0;
    }
  }

  Array(const Array& other) {
    // std::cout << "Array: copy constructor called" << std::endl;
    this->_n = 0;
    this->_arr = nullptr;
    *this = other;
  }

  Array& operator=(const Array& other) {
    // std::cout << "Array: copy assignment operator called" << std::endl;

    // guard self assignment
    if (this == &other) {
      return *this;
    }

    if (this->_arr != nullptr) {
      delete[] this->_arr;
      this->_arr = nullptr;
    }

    this->_n = 0;

    if (other._n == 0 || other._arr == nullptr) {
      return *this;
    }

    this->_arr = new (std::nothrow) T[other._n];
    if (this->_arr == nullptr) {
      std::cerr << "Error: Array: Memory allocation failed" << std::endl;
      return *this;
    }

    this->_n = other._n;
    for (unsigned int i = 0; i < other._n; i++) {
      this->_arr[i] = other._arr[i];
    }

    return *this;
  }

  ~Array() {
    std::cout << "Array: destructor called";
    ;
    if (_arr != nullptr) {
      delete[] _arr;
      std::cout << " (freed)" << std::endl;
    } else {
      std::cout << " (nullptr)" << std::endl;
    }
  }

  T& operator[](unsigned int n) {
    if (n >= this->_n) {
      throw std::out_of_range("Error: Array: Index " + std::to_string(n) +
                              " is out of bounds");
    }
    return this->_arr[n];
  }

  // size accessor
  unsigned int size() const { return _n; }

 private:
  unsigned int _n;
  T* _arr;
};

#endif  // ARRAY_EX02_HPP_