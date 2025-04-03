/**
 * @file Bureaucrat.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Doctor Strange"), _grade(1) {
  std::cout << "Bureaucrat " << _name << ": default constructor called"
            << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException(*this);
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException(*this);
  } else {
    std::cout << "Bureaucrat " << _name << ": parametrized constructor called"
              << std::endl;
    _grade = grade;
  }
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << _name << ": destructor called" << std::endl;
}

const std::string& Bureaucrat::getName(void) const { return _name; }

const int& Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void) {
  int new_grade = _grade - 1;
  if (new_grade < 1) {
    throw Bureaucrat::GradeTooHighException(*this);
  } else {
    _grade = new_grade;
  }
}

void Bureaucrat::decrementGrade(void) {
  int new_grade = _grade + 1;
  if (new_grade > 150) {
    throw Bureaucrat::GradeTooLowException(*this);
  } else {
    _grade = new_grade;
  }
}

void Bureaucrat::signForm(Form& form) {
  try {
    if (form.isSigned() == false) {
      std::cout << "Bureaucrat " << MAGENTA << this->getName() << RESET
                << " signed form '" << form.getName() << "'" << std::endl;
    }
    form.beSigned(*this);
  } catch (const std::exception& e) {
    std::cerr << "Bureaucrat " << this->getName()
              << "couldn't sign form '" << form.getName() << "', because:\n\t"
              << RED << e.what() << RESET << std::endl;
  }
}

// Exception GradeTooLowException

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : _message("Error: Bureaucrat: Grade too low") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat& obj)
    : _message("Error: Bureaucrat " + obj.getName() + ": Grade too low") {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
  return _message.c_str();
}

// Exception GradeTooHighException

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : _message("Error: Bureaucrat: Grade too high") {}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat& obj)
    : _message("Error: Bureaucrat " + obj.getName() + ": Grade too high") {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
  return _message.c_str();
}

// Operators

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
  os << MAGENTA << b.getName() << RESET << ", bureaucrat grade " << BLUE
     << b.getGrade() << RESET;
  return os;
}