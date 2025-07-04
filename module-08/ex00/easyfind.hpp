#pragma once

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <string>
#include <type_traits>

template <typename T>
auto easyfind(T& container,
              const int value) -> decltype(std::begin(container),
                                           std::end(container),
                                           *std::begin(container)) {
  auto it = std::find(std::begin(container), std::end(container), value);
  if (it == std::end(container))
    throw std::out_of_range("Error: easyfind: value " + std::to_string(value) +
                            " not found");
  return *it;
}

template <typename T>
auto easyfind(const T& container,
              const int value) -> decltype(std::begin(container),
                                           std::end(container),
                                           *std::begin(container)) {
  auto it = std::find(std::begin(container), std::end(container), value);
  if (it == std::end(container))
    throw std::out_of_range("Error: easyfind: value " + std::to_string(value) +
                            " not found");
  return *it;
}
