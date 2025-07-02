#include "ScalarConverter.hpp"

/**
 * 1. detect the type of the literal passed as a parameter
 * 2. convert it from string to its actual type
 * 3. then convert it explicitly to the three other data types
 * 4. display the results
 */
void ScalarConverter::convert(const std::string& literal) {
  if (isChar(literal)) {
    char ch = static_cast<unsigned char>(literal[0]);
    int i = static_cast<int>(ch);
    float f = static_cast<float>(ch);
    double d = static_cast<double>(ch);
    std::cout << "char: "
              << (std::isprint(ch) ? std::string(1, ch) : "not printable")
              << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
              << std::endl;
    std::cout << "double: " << d << std::defaultfloat << std::endl;
    return;
  }

  if (isIntenger(literal)) {
    int i = 0;
    try {
      i = std::stoi(literal);
    } catch (...) {
      std::cerr << "Error: Intenger is out of range";
    }
    char ch = static_cast<unsigned char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    if (i != ch)
      std::cout << "char: "
                << "impossible" << std::endl;
    else
      std::cout << "char: "
                << (std::isprint(ch) ? std::string(1, ch) : "not printable")
                << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
              << std::endl;
    std::cout << "double: " << d << std::defaultfloat << std::endl;
    return;
  }

  if (isFloat(literal)) {
    try {
      float f = std::stof(literal);
      int i = static_cast<int>(std::round(f));
      char ch = static_cast<unsigned char>(std::round(f));
      double d = static_cast<double>(f);
      if (i < 0 || i > 255)
        std::cout << "char: "
                  << "impossible" << std::endl;
      else
        std::cout << "char: "
                  << (std::isprint(ch) ? std::string(1, ch) : "not printable")
                  << std::endl;
      std::cout << "int: " << i << std::endl;
      std::cout << "float: " << f << "f" << std::endl;
      std::cout << "double: " << d << std::endl;
    } catch (...) {
      std::cerr << "Error: Out-of-range float";
    }
    return ;
  }

  if (isDouble(literal)) {
    try {
      double d = std::stod(literal);
      int i = static_cast<int>(std::round(d));
      char ch = static_cast<unsigned char>(std::round(d));
      float f = static_cast<float>(d);
      if (d < 0.0 || d > 255.0 || std::isnan(d) || i != ch)
        std::cout << "char: "
                  << "impossible" << std::endl;
      else
        std::cout << "char: "
                  << (std::isprint(ch) ? std::string(1, ch) : "not printable")
                  << std::endl;
      if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
          d > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << "char: "
                  << "impossible" << std::endl;
        std::cout << "int: "
                  << "impossible" << std::endl;
      } else {
        std::cout << "int: " << i << std::endl;
      }
      if (!std::isfinite(f)) {
        std::cout << "float: "
                  << "impossible" << std::endl;
      } else {
        std::cout << "float: " << f << "f" << std::endl;
      }
      std::cout << "double: " << d << std::endl;
      return;
    } catch (...) {
      std::cerr << "Error: Out-of-range double";
    }
    return;
  }
}