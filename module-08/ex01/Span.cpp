#include "Span.hpp"

#include <algorithm>

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() { _vec.clear(); }

void Span::addNumber(int value) {
  if (_vec.size() >= _n)
    throw std::out_of_range("Error: addNumber: Exceed capacity in " +
                            std::to_string(_n) + " elements");
  _vec.push_back(value);
  _n += 1;
}
int Span::shortestSpan() {
  if (_vec.empty())
    throw std::length_error("Error: shortestSpan: Span is empty");
  if (_vec.size() == 1)
    throw std::length_error(
        "Error: shortestSpan: Span contains only one element");
  std::vector<int> tmp = _vec;
  std::sort(tmp.begin(), tmp.end());
  int res = tmp[1] - tmp[0];
  int tmp_res = 0;
  for (auto start = tmp.begin(), end = tmp.end(); start + 1 != end && res != 0;
       start++) {
    tmp_res = start[1] - start[0];
    if (tmp_res < res) res = tmp_res;
  }
  return res;
}

int Span::longestSpan() {
  if (_vec.empty())
    throw std::length_error("Error: shortestSpan: Span is empty");
  if (_vec.size() == 1)
    throw std::length_error(
        "Error: shortestSpan: Span contains only one element");
  std::vector<int> tmp = _vec;
  std::sort(tmp.begin(), tmp.end());
  return *(tmp.end() - 1) - *(tmp.begin());
}
