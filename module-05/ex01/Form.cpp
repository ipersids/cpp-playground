/**
 * @file Form.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "Form.hpp"

Form::Form()
    : _name("Certificate of participation"),
      _is_signed(false),
      _grade_to_sign(150),
      _grade_to_execute(150) {
  std::cout << "Form '" << _name << "': default constructor called"
            << std::endl;
}

Form::Form(const std::string name, const int grade_to_sign,
           const int grade_to_execute)
    : _name(name),
      _is_signed(false),
      _grade_to_sign(grade_to_sign),
      _grade_to_execute(grade_to_execute) {
  if (grade_to_sign < 1 || grade_to_execute < 1) {
    throw Form::GradeTooHighException(*this);
  } else if (grade_to_sign > 150 || grade_to_execute > 150) {
    throw Form::GradeTooLowException(*this);
  } else {
    std::cout << "Form '" << _name << "': parametrized constructor called"
              << std::endl;
  }
}

Form::~Form() {
  std::cout << "Form '" << _name << "': destructor called" << std::endl;
}

const std::string& Form::getName(void) const { return _name; }

bool Form::isSigned(void) const { return _is_signed; }

int Form::getGradeToSign(void) const { return _grade_to_sign; }

int Form::getGradeToExecute(void) const { return _grade_to_execute; }

void Form::beSigned(const Bureaucrat& who) {
  const int grade = who.getGrade();
  if (grade > _grade_to_sign) {
    throw Form::GradeTooLowException(*this);
  } else if (grade < 1) {
    throw Form::GradeTooHighException(*this);
  } else if (_is_signed == true) {
    std::cout << "Form '" << _name << "': is already singed" << std::endl;
  } else {
    _is_signed = true;
  }
}

// Exception GradeTooHighException

Form::GradeTooHighException::GradeTooHighException()
    : _message("Error: Form: Grade too high") {}

Form::GradeTooHighException::GradeTooHighException(const Form& form)
    : _message("Error: Form '" + form.getName() + "':  Grade too high") {}

const char* Form::GradeTooHighException::what() const noexcept {
  return _message.c_str();
}

// Exception GradeTooLowException

Form::GradeTooLowException::GradeTooLowException()
    : _message("Error: Form: Grade too low") {}

Form::GradeTooLowException::GradeTooLowException(const Form& form)
    : _message("Error: Form '" + form.getName() + "':  Grade too low") {}

const char* Form::GradeTooLowException::what() const noexcept {
  return _message.c_str();
}

// Operators

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form information:"
     << "\n- name: " << MAGENTA << f.getName() << RESET
     << "\n- signed status: " << (f.isSigned() ? GREEN "true" : RED "false")
     << RESET << "\n- grade to sign: " << BLUE << f.getGradeToSign() << RESET
     << "\n- grade to execute: " << BLUE << f.getGradeToExecute() << RESET;
  return os;
}