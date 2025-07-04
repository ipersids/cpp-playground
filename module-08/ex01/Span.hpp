#pragma once

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
 public:
  Span() = delete;
  Span(unsigned int n);
  Span& operator=(const Span& other) = delete;
  Span(const Span& other) = delete;
  ~Span();

  void addNumber(int value);
  int shortestSpan();
  int longestSpan();

 private:
  unsigned int _n;
  std::vector<int> _vec;
};
