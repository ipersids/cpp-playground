#include "utils.hpp"

/* ----------------- DISPLAY RESULT ---------------- */

void displayError(const std::string& ch, const std::string& i, const std::string& f, const std::string& d) {
  std::cout << "char: " << ch << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << std::endl;
  std::cout << "double: " << d << std::endl;
}

/* ---------------- CHECK DATA TYPE ---------------- */
/// @note regex tutorial: 
/// https://www3.ntu.edu.sg/home/ehchua/programming/howto/Regexe.html

bool isChar(const std::string& literal) {
  std::regex re(R"(^.$)");
  return (std::regex_match(literal, re) || literal.length() == 1) && !std::isdigit(literal[0]);
}

bool isIntenger(const std::string& literal) {
  std::regex re(R"(^\s*[+-]?[1-9]\d*\s*|\s*0\s*$)");
  return std::regex_match(literal, re);
}

bool isFloat(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?f\s*$)");
  return std::regex_match(literal, re);
}

bool isDouble(const std::string& literal) {
  std::regex re(R"(^\s*(-|\+)?(\d+|(\d*(\.\d*)))([eE][+-]?\d+)?\s*$)");
  return std::regex_match(literal, re);
}

/* ----------------- TRY TO CONVERT ----------------- */

int tryToIntenger(const std::string& literal) {
  int i = 0;
  std::ostringstream msg;
  try {
    i = std::stoi(literal);
    return i;
  }
  catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  }
  catch (std::out_of_range const& ex) {
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
  }
  catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  }
  catch (std::out_of_range const& ex) {
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
  }
  catch (std::invalid_argument const& ex) {
    msg << "Error: " << ex.what() << '\n';
  }
  catch (std::out_of_range const& ex) {
    msg << "Error: " << ex.what();
  }
  displayError("Impossible", "Impossible", "Impossible", msg.str());
  std::exit(3);
}

/* ------------------ CALCULATIONS ------------------ */
