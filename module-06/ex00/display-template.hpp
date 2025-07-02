#pragma once

#include <iomanip>
#include <iostream>

template <typename F, typename T>
void displayType(const std::string& type, F from_data, T to_data,
                 bool is_fixed_presicion) {
  bool is_possible = !(
      static_cast<long double>(from_data) < std::numeric_limits<T>::lowest() ||
      static_cast<long double>(from_data) > std::numeric_limits<T>::max());
  if (is_fixed_presicion)
    std::cout << std::setprecision(1) << std::fixed;
  else
    std::cout << std::defaultfloat;
  if (is_possible && type == "char" && from_data >= 0) {
    std::cout << type << ": "
              << (std::isprint(to_data) ? std::string(1, to_data)
                                        : "not printable")
              << std::endl;
  } else if (is_possible && type == "float")
    std::cout << type << ": " << to_data << "f" << std::endl;
  else if (is_possible)
    std::cout << type << ": " << to_data << std::endl;
  else
    std::cout << type << ": Impossible" << std::endl;
}
