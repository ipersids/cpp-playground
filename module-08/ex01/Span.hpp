#pragma once

#include <algorithm>
#include <concepts>
#include <iostream>
#include <iterator>  // std::input_iterator concept
#include <stdexcept>
#include <vector>

#ifdef __cpp_concepts
#include <concepts>  // c++20 concept support
#else
#include <type_traits>
#endif

#define COLORED_ERR "\033[31mError:\033[0m"

class Span {
 public:
  Span() = delete;
  Span(unsigned int n);
  Span& operator=(const Span& other) = delete;
  Span(const Span& other) = delete;
  ~Span();

  void addNumber(int value);

#ifdef __cpp_concepts
  template <std::input_iterator InputIt>
#else
  template <typename InputIt,
            typename std::enable_if<std::is_base_of_v<
                std::input_iterator_tag,
                typename std::iterator_traits<InputIt>::iterator_category> > >
#endif
  void addNumber(InputIt begin, InputIt end) {
    size_t distance = std::distance(begin, end);
    if (_vec.size() + distance > _n) {
      throw std::out_of_range(COLORED_ERR " addNumber: Exceed capacity in " +
                              std::to_string(_n) + " elements");
    }
    _vec.insert(_vec.end(), begin, end);
  }

  unsigned int shortestSpan();
  unsigned int longestSpan();

 private:
  unsigned int _n;
  std::vector<int> _vec;
};
