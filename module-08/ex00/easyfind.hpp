#pragma once

#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
typename T::value_type& easyfind(T& container, const int value) {
  auto it = std::find(std::begin(container), std::end(container), value);
  if (it == std::end(container))
    throw std::out_of_range("Error: easyfind: value " + std::to_string(value) +
                            " not found");
  return *it;
}

template <typename T>
const typename T::value_type& easyfind(const T& container, const int value) {
  auto it = std::find(std::begin(container), std::end(container), value);
  if (it == std::end(container))
    throw std::out_of_range("Error: easyfind: value " + std::to_string(value) +
                            " not found");
  return *it;
}
