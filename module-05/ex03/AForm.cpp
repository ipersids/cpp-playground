/**
 * @file Form.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "AForm.hpp"

AForm::AForm()
    : _name("Certificate of participation"),
      _is_signed(false),
      _grade_to_sign(150),
      _grade_to_execute(150) {
  std::cout << "AForm '" << _name << "': default constructor called"
            << std::endl;
}

AForm::AForm(const std::string name, const int grade_to_sign,
             const int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {
  if (grade_to_sign < 1 || grade_to_execute < 1) {
    throw AForm::GradeTooHighException(*this);
  } else if (grade_to_sign > 150 || grade_to_execute > 150) {
    throw AForm::GradeTooLowException(*this);
  } else {
    std::cout << "AForm '" << _name << "': parametrized constructor called"
              << std::endl;
  }
}

AForm::~AForm() {
  std::cout << "AForm '" << _name << "': destructor called" << std::endl;
}

const std::string& AForm::getName(void) const { return _name; }

bool AForm::isSigned(void) const { return _is_signed; }

int AForm::getGradeToSign(void) const { return _grade_to_sign; }

int AForm::getGradeToExecute(void) const { return _grade_to_execute; }

void AForm::beSigned(const Bureaucrat& who) {
  const int grade = who.getGrade();
  if (grade > _grade_to_sign) {
    throw AForm::GradeTooLowException(*this);
  } else if (grade < 1) {
    throw AForm::GradeTooHighException(*this);
  } else if (_is_signed == true) {
    std::cout << "AForm '" << _name << "': is already singed" << std::endl;
  } else {
    _is_signed = true;
  }
}

void AForm::checkRightToExecute(Bureaucrat const& executor) const {
  const int grade = executor.getGrade();

  if (this->_grade_to_execute < grade) {
    throw GradeTooLowException(*this);
  }

  if (_is_signed == false) {
    throw FormIsNotSingedException(*this);
  }
}

// Exception GradeTooHighException

AForm::GradeTooHighException::GradeTooHighException(const AForm& form)
    : _message("Error: AForm '" + form.getName() + "':  Grade too high") {}

const char* AForm::GradeTooHighException::what() const noexcept {
  return _message.c_str();
}

// Exception GradeTooLowException

AForm::GradeTooLowException::GradeTooLowException(const AForm& form)
    : _message("Error: AForm '" + form.getName() + "':  Grade too low") {}

const char* AForm::GradeTooLowException::what() const noexcept {
  return _message.c_str();
}

// Exception FormIsNotSingedException

AForm::FormIsNotSingedException::FormIsNotSingedException(const AForm& form)
    : _message("Error: AForm '" + form.getName() + "':  Is not singed yet") {}

const char* AForm::FormIsNotSingedException::what() const noexcept {
  return _message.c_str();
}

// Operators

std::ostream& operator<<(std::ostream& os, const AForm& f) {
  os << "AForm information:"
     << "\n- name: " << MAGENTA << f.getName() << RESET
     << "\n- signed status: " << (f.isSigned() ? GREEN "true" : RED "false")
     << RESET << "\n- grade to sign: " << BLUE << f.getGradeToSign() << RESET
     << "\n- grade to execute: " << BLUE << f.getGradeToExecute() << RESET;
  return os;
}