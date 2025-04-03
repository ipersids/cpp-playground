/**
 * @file Form.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef AFORM_EX03_HPP_
#define AFORM_EX03_HPP_

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;  // forward declaration

class AForm {
 public:
  AForm();
  AForm(const std::string name, const int grade_to_sign,
        const int grade_to_execute);
  AForm(const AForm& other) = delete;
  AForm& operator=(const AForm& other) = delete;
  virtual ~AForm();

  const std::string& getName(void) const;
  bool isSigned(void) const;
  int getGradeToSign(void) const;
  int getGradeToExecute(void) const;

  void beSigned(const Bureaucrat& who);
  // pure virtual function to make the class abstract
  virtual void execute(Bureaucrat const& executor) const = 0;
  void checkRightToExecute(Bureaucrat const& executor) const;

  class GradeTooHighException : public std::exception {
   public:
    GradeTooHighException(const AForm& form);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

  class GradeTooLowException : public std::exception {
   public:
    GradeTooLowException(const AForm& form);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

  class FormIsNotSingedException : public std::exception {
   public:
    FormIsNotSingedException(const AForm& form);

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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif  // AFORM_EX03_HPP_