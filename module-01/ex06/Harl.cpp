/**
 * @file Harl.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "Harl.hpp"

Harl::Harl() {
  _complaints[0] = &Harl::debug;
  _complaints[1] = &Harl::info;
  _complaints[2] = &Harl::warning;
  _complaints[3] = &Harl::error;
  _types[0] = "DEBUG";
  _types[1] = "INFO";
  _types[2] = "WARNING";
  _types[3] = "ERROR";
}

void Harl::debug(void) {
  std::cout << "[ DEBUG ]\nI love having extra bacon for my "
            << "7XL-double-cheese-triple-pickle-specialketchup burger.\n"
            << "I really do!" << std::endl;
}

void Harl::info(void) {
  std::cout
      << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n"
      << "You didn't put enough bacon in my burger! If you did, "
      << "I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
      << "I've been coming for years whereas you started "
      << "working here since last month." << std::endl;
}

void Harl::error(void) {
  std::cout
      << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
      << std::endl;
}

void Harl::complain(std::string level) {
  int i = 0;
  while (i < TYPE_COUNT && _types[i] != level) {
    i++;
  }

  switch (i) {
    case 0:
      (this->*_complaints[0])();

    case 1:
      (this->*_complaints[1])();

    case 2:
      (this->*_complaints[2])();

    case 3:
      (this->*_complaints[3])();
      break;

    default:
      std::cout << "[ Probably complaining about insignificant problems ]"
                << std::endl;
      break;
  }
}