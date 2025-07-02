#pragma once

#include "display-template.hpp"
#include "utils.hpp"

class ScalarConverter {
 public:
  ScalarConverter() = delete;
  ~ScalarConverter() = default;
  ScalarConverter& operator=(const ScalarConverter& other) = delete;
  ScalarConverter(const ScalarConverter& other) = delete;

  static void convert(const std::string& literal);
};