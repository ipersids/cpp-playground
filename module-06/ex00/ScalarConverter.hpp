#pragma once

#include <iostream>
#include <iomanip>

#include "utils.hpp"

class ScalarConverter {
  public:
    ScalarConverter() = delete;
    ~ScalarConverter() = default;
    ScalarConverter& operator=(const ScalarConverter& other) = delete;
    ScalarConverter(const ScalarConverter& other) = delete;

    static void convert(const std::string& literal);
};