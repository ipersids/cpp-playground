#pragma once

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdexcept>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

class BitcoinExchange {
 public:
  BitcoinExchange();
  BitcoinExchange& operator=(const BitcoinExchange& other) = delete;
  BitcoinExchange(const BitcoinExchange& other) = delete;
  ~BitcoinExchange();

  void exchange(const std::string& input_path);

 protected:
  static std::string _database_path;

 private:
  std::map<std::string, float> _database;

  void loadDatabase();
  bool validateDate(const std::string& date) const;
  bool validateValue(const std::string& value, float* result, float max_value);
};