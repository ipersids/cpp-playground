#include "BitcoinExchange.hpp"

std::string BitcoinExchange::_database_path = "./data.csv";

BitcoinExchange::BitcoinExchange() { this->loadDatabase(); }

BitcoinExchange::~BitcoinExchange() { _database.clear(); }

void BitcoinExchange::exchange(const std::string& input_path) {
  std::ifstream fs;
  fs.open(input_path, std::fstream::in);

  if (!fs.is_open()) {
    throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                "Invalid path to the input file");
  }

  std::string line;
  float val = 0.0;
  double result = 0.0;
  std::getline(fs, line);

  if (line != "date | value") {
    throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                "Invalid header in input file: " + line);
  }

  while (std::getline(fs, line)) {
    std::istringstream iss(line);
    if (iss.fail()) {
      throw std::bad_cast();
    }
    std::string date, delimiter, value;
    iss >> date >> delimiter >> value;
    if (delimiter != "|") {
      std::cout << RED "Error: " << RESET
                << "Input file contents invalid delimiter: " << line
                << std::endl;
      continue;
    }
    if (!validateDate(date)) {
      continue;
    }
    if (!validateValue(value, &val, 1000.0)) {
      continue;
    }

    auto it = _database.lower_bound(date);
    if (it == _database.end() || (it != _database.begin() && date != it->first))
      --it;
    result = static_cast<double>(it->second) * static_cast<double>(val);
    std::cout << date << " => " << val << " =\t" << BLUE << result << RESET
              << std::endl;
  }

  fs.close();
}

/// Private helper functions

void BitcoinExchange::loadDatabase() {
  std::ifstream fs;
  fs.open(_database_path, std::fstream::in);
  if (!fs.is_open()) {
    std::cerr << MAGENTA "Warning: " << RESET
              << "Can not find database file with default path: '"
              << _database_path << "'" << std::endl;
    std::cout << "Input new path: " << std::flush;
    std::cin >> _database_path;
    fs.open(_database_path, std::fstream::in);
    if (!fs.is_open()) {
      throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                  "Invalid path to database file");
    }
  }

  std::string line;
  float val = 0.0;
  std::getline(fs, line);

  if (line != "date,exchange_rate") {
    fs.close();
    line.clear();
    throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                "Invalid header in database file: " + line);
  }
  line.clear();

  while (std::getline(fs, line)) {
    std::replace(line.begin(), line.end(), ',', ' ');
    std::istringstream iss(line);
    if (iss.fail()) {
      fs.close();
      throw std::bad_cast();
    }
    std::string date, value;
    iss >> date >> value;
    if (!validateDate(date)) {
      fs.close();
      throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                  "Database contents invalid date");
    }
    if (!validateValue(value, &val, std::numeric_limits<float>::max())) {
      fs.close();
      throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                  "Database contents invalid value");
    }
    _database[date] = val;
    line.clear();
  }

  fs.close();

  if (_database.empty()) {
    throw std::invalid_argument(RED "Error: " + std::string(RESET) +
                                "Empty database");
  }
}

bool BitcoinExchange::validateDate(const std::string& date) const {
  if (date.empty()) {
    std::cout << RED "Error: " << RESET << "Empty date: (null)" << std::endl;
    return false;
  }

  std::regex re(R"(^(\d{4})-(\d{2})-(\d{2})$)");
  std::smatch matched_content;
  if (!std::regex_match(date, matched_content, re)) {
    std::cout << RED "Error: " << RESET << "Invalid date format: " << date
              << std::endl;
    return false;
  }

  int year, month, day = 0;
  try {
    year = std::stoi(matched_content[1]);
    month = std::stoi(matched_content[2]);
    day = std::stoi(matched_content[3]);
  } catch (const std::exception& e) {
    std::cout << RED "Error: " << RESET << e.what() << ": " << date
              << std::endl;
    return false;
  }

  if (year < 2008 || (year == 2008 && month < 8) ||
      (year == 2008 && month == 8 && day < 18)) {
    std::cout << RED "Error: " << RESET
              << "Date before bitcoins were even launched: " << date
              << std::endl;
    return false;
  }

  std::time_t now = std::time(nullptr);
  std::tm* now_local = std::localtime(&now);
  int now_year = now_local->tm_year + 1900;
  int now_month = now_local->tm_mon + 1;
  int now_day = now_local->tm_mday;

  if (year > now_year || (year == now_year && month > now_month) ||
      (year == now_year && month == now_month && day > now_day)) {
    std::cout << RED "Error: " << RESET
              << "Are you from future? Because date is: " << date << std::endl;
    return false;
  }

  if (month < 1 || month > 12) {
    std::cout << RED "Error: " << RESET
              << "Invalid calendar date: Wrong month: " << date << std::endl;
    return false;
  }

  int max_days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  bool leapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  if (leapYear) {
    max_days_per_month[1] = 29;
  }

  if (day < 1 || day > max_days_per_month[month - 1]) {
    std::cout << RED "Error: " << RESET
              << "Invalid calendar date: Wrong day: " << date << std::endl;
    return false;
  }

  return true;
}

bool BitcoinExchange::validateValue(const std::string& value, float* result,
                                    float max_value) {
  if (value.empty()) {
    std::cout << RED "Error: " << RESET << "Empty value: (null)" << std::endl;
    return false;
  }

  double val = 0;
  size_t index = 0;
  try {
    val = std::stod(value, &index);
  } catch (const std::exception& e) {
    std::cout << RED "Error: " << RESET << e.what() << ": " << value
              << std::endl;
    return false;
  }

  if (index != value.size()) {
    std::cout << RED "Error: " << RESET << "Invalid value format: " << value
              << std::endl;
    return false;
  }

  if (val < 0.0 || val > max_value) {
    std::cout << RED "Error: " << RESET << "Invalid value: " << value
              << " (should be between 0 and " << max_value << ")" << std::endl;
    return false;
  }

  *result = static_cast<float>(val);
  return true;
}
