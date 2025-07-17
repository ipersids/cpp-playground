#include "Span.hpp"

#include <algorithm>

Span::Span(unsigned int n) : _n(n) { _vec.reserve(n); }

Span::~Span() { _vec.clear(); }

void Span::addNumber(int value) {
  if (_vec.size() >= _n)
    throw std::out_of_range(COLORED_ERR " addNumber: Exceed capacity in " +
                            std::to_string(_n) + " elements");
  _vec.push_back(value);
}

unsigned int Span::shortestSpan() {
  if (_vec.empty())
    throw std::length_error(COLORED_ERR " shortestSpan: Span is empty");
  if (_vec.size() == 1)
    throw std::length_error(COLORED_ERR
                            " shortestSpan: Span contains only one element");

  std::vector<int> tmp = _vec;
  std::sort(tmp.begin(), tmp.end());

  unsigned int res = std::numeric_limits<unsigned int>::max();

  for (size_t i = 0; i < tmp.size() - 1; ++i) {
    unsigned int current_span = static_cast<unsigned int>(
      static_cast<long int>(tmp[i + 1]) - static_cast<long int>(tmp[i])
    );
    if (current_span < res) {
      res = current_span;
    }
  }

  return res;
}

unsigned int Span::longestSpan() {
  if (_vec.empty())
    throw std::length_error(COLORED_ERR " longestSpan: Span is empty");
  if (_vec.size() == 1)
    throw std::length_error(COLORED_ERR
                            " longestSpan: Span contains only one element");
  std::vector<int> tmp = _vec;
  std::sort(tmp.begin(), tmp.end());
  return *(tmp.end() - 1) - *(tmp.begin());
}
