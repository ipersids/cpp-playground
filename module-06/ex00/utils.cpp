#include "utils.hpp"

/* ----------------- DISPLAY RESULT ---------------- */

void displayError(const std::string& ch, const std::string& i,
                  const std::string& f, const std::string& d) {
  std::cout << "char: " << ch << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "double: " << d << std::endl;
}

void displayNanOrInfinity(float f, double d) {
  std::cout << "char: Impossible" << std::endl;
  std::cout << "int: Impossible" << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "double: " << d << std::endl;
}

void displayInvalidInput(void) {
  std::cout << "char: Impossible" << std::endl;
  std::cout << "int: Impossible" << std::endl;
  std::cout << "float: Impossible" << std::endl;
  std::cout << "double: Impossible" << std::endl;
}

/* ---------------- CHECK DATA TYPE ---------------- */
/// @note regex tutorial:
/// https://www3.ntu.edu.sg/home/ehchua/programming/howto/Regexe.html

bool isChar(const std::string& literal) {
  std::regex re(R"(^.$)");
  return (std::regex_match(literal, re) || literal.length() == 1) &&
         !std::isdigit(literal[0]);
}

bool isIntenger(const std::string& literal) {
  std::regex re(R"(^\s*[+-]?[1-9]\d*\s*|\s*0\s*$)");
  return std::regex_match(literal, re);
}

bool isFloat(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?f\s*$)");
  return std::regex_match(literal, re) || isNanOrInfinity(literal);
}

bool isDouble(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?\s*$)");
  return std::regex_match(literal, re) || isNanOrInfinity(literal);
}

bool isNanOrInfinity(const std::string& literal) {
  std::regex re(R"(^\s*[+-]?(inf(inity)?|nan)f?\s*$)", std::regex::icase);
  return std::regex_match(literal, re);
}

/* ----------------- TRY TO CONVERT ----------------- */

int tryToIntenger(const std::string& literal) {
  int i = 0;
  std::ostringstream msg;
  try {
    i = std::stoi(literal);
    return i;
  } catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  } catch (std::out_of_range const& ex) {
    msg << "Error: " << ex.what();
  }
  displayError("Impossible", msg.str(), "Impossible", "Impossible");
  std::exit(1);
}

float tryToFloat(const std::string& literal) {
  float f = 0.0;
  std::ostringstream msg;
  try {
    f = std::stof(literal);
    return f;
  } catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  } catch (std::out_of_range const& ex) {
    msg << "Error: " << ex.what();
  }
  displayError("Impossible", "Impossible", msg.str(), "Impossible");
  std::exit(2);
}

double tryToDouble(const std::string& literal) {
  double d = 0.0;
  std::ostringstream msg;
  try {
    d = std::stod(literal);
    return d;
  } catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  } catch (std::out_of_range const& ex) {
    msg << "Error: " << ex.what();
  }
  displayError("Impossible", "Impossible", "Impossible", msg.str());
  std::exit(3);
}

/* -------------------- CHECKERS -------------------- */

bool isFixedPrecision(const std::string& literal) {
  std::size_t dot_pos = literal.find('.');
  if (dot_pos == std::string::npos) return true;

  std::size_t exp_pos = literal.find_first_of("eE", dot_pos);
  std::size_t first_non_zero_pos = literal.find_first_not_of('0', dot_pos + 1);
  if (exp_pos == std::string::npos && first_non_zero_pos == std::string::npos) {
    return true;
  }
  if (exp_pos == std::string::npos) {
    return false;
  }
  int decimal_precision_count =
      static_cast<int>(exp_pos) - static_cast<int>(dot_pos) - 1;
  int exponent = 0;
  try {
    exponent = std::stoi(literal.substr(exp_pos + 1));
  } catch (...) {
    std::cout << "Error: isFixedPresicion() -> stoi" << std::endl;
    return false;
  }
  return !(exponent < decimal_precision_count) ||
         (exp_pos == first_non_zero_pos);
}
