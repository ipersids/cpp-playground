/**
 * @file Form.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef FORM_EX01_HPP_
#define FORM_EX01_HPP_

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;  // forward declaration

class Form {
 public:
  Form();
  Form(const std::string name, const int grade_to_sign,
       const int grade_to_execute);
  Form(const Form& other) = delete;
  Form& operator=(const Form& other) = delete;
  ~Form();

  const std::string& getName(void) const;
  bool isSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExecute(void) const;

  void beSigned(const Bureaucrat& who);

  class GradeTooHighException : public std::exception {
   public:
    GradeTooHighException();
    GradeTooHighException(const Form& form);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

  class GradeTooLowException : public std::exception {
   public:
    GradeTooLowException();
    GradeTooLowException(const Form& form);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

 private:
  const std::string _name;
  bool _is_signed;
  const int _grade_to_sign;
  const int _grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif  // FORM_EX01_HPP_