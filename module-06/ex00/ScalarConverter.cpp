#include "ScalarConverter.hpp"

/**
 * 1. detect the type of the literal passed as a parameter
 * 2. convert it from string to its actual type
 * 3. then convert it explicitly to the three other data types
 * 4. display the results
 */
void ScalarConverter::convert(const std::string& literal) {
  if (isChar(literal)) {
    unsigned char ch = static_cast<unsigned char>(literal[0]);
    int i = static_cast<int>(ch);
    float f = static_cast<float>(ch);
    double d = static_cast<double>(ch);
    displayType("char", ch, ch, false);
    displayType("int", ch, i, false);
    displayType("float", ch, f, true);
    displayType("double", ch, d, true);
    return;
  }

  if (isIntenger(literal)) {
    int i = tryToIntenger(literal);
    unsigned char ch = static_cast<unsigned char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    displayType("char", i, ch, false);
    displayType("int", i, i, false);
    displayType("float", i, f, true);
    displayType("double", i, d, true);
    return;
  }

  if (isFloat(literal)) {
    float f = tryToFloat(literal);
    int i = static_cast<int>(std::round(f));
    unsigned char ch = static_cast<unsigned char>(std::round(f));
    double d = static_cast<double>(f);
    if (!std::isfinite(f) || std::isnan(f)) {
      displayNanOrInfinity(f, d);
      return ;
    }
    bool is_fixed_precision = isFixedPrecision(literal);
    displayType("char", f, ch, false);
    displayType("int", f, i, false);
    displayType("float", f, f, is_fixed_precision);
    displayType("double", f, d, is_fixed_precision);
    return ;
  }

  if (isDouble(literal)) {
    double d = tryToDouble(literal);
    int i = static_cast<int>(std::round(d));
    unsigned char ch = static_cast<unsigned char>(std::round(d));
    float f = static_cast<float>(d);
    if (!std::isfinite(f) || std::isnan(f)) {
      displayNanOrInfinity(f, d);
      return ;
    }
    bool is_fixed_precision = isFixedPrecision(literal);
    displayType("char", d, ch, false);
    displayType("int", d, i, false);
    displayType("float", d, f, is_fixed_precision);
    displayType("double", d, d, is_fixed_precision);
    return;
  }
}
