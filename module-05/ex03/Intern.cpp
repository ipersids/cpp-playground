/**
 * @file Intern.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern: default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
  std::cout << "Intern: copy constructor called" << std::endl;
  *this = other;
}

Intern& Intern::operator=(const Intern& other) {
  std::cout << "Intern: copy assigning constructor called" << std::endl;
  if (this == &other) {
    return *this;
  }
  *this = other;
  return *this;
}

Intern::~Intern() { std::cout << "Intern: destructor called" << std::endl; }

AForm* Intern::makeForm(const std::string& form_name,
                        const std::string& target) {
  const std::string arr[FORMS_AMOUNT] = {
      "robotomy request", "shrubbery creation", "presidential pardon"};
  int i = 0;
  while (i < FORMS_AMOUNT) {
    if (arr[i] == form_name) {
      break;
    }
    ++i;
  }

  AForm* result = nullptr;

  switch (i) {
    case 0:
      result = new (std::nothrow) RobotomyRequestForm(target);
      break;

    case 1:
      result = new (std::nothrow) ShrubberyCreationForm(target);
      break;

    case 2:
      result = new (std::nothrow) PresidentialPardonForm(target);
      break;

    default:
      std::cerr << RED << "Error: Intern: uknown form name" << RESET
                << std::endl;
      return nullptr;
  }

  if (result == nullptr) {
    std::cerr << RED << "Error: Intern: allocation memory failed" << RESET
              << std::endl;
  }

  return result;
}