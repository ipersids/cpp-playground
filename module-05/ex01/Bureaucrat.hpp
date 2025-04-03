/**
 * @file Bureaucrat.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef BUREAUCRAT_EX01_HPP_
#define BUREAUCRAT_EX01_HPP_

#include <iostream>
#include <stdexcept>

#include "Form.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

class Form;  // forward declaration

class Bureaucrat {
 public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& other) = delete;
  Bureaucrat& operator=(const Bureaucrat& other) = delete;
  ~Bureaucrat();

  const std::string& getName(void) const;
  const int& getGrade(void) const;
  void incrementGrade(void);
  void decrementGrade(void);
  void signForm(Form& form);

  class GradeTooHighException : public std::exception {
   public:
    GradeTooHighException();
    GradeTooHighException(const Bureaucrat& obj);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

  class GradeTooLowException : public std::exception {
   public:
    GradeTooLowException();
    GradeTooLowException(const Bureaucrat& obj);

    const char* what() const noexcept override;

   private:
    const std::string _message;
  };

 private:
  const std::string _name;
  int _grade;  // range from 1 (highest) to 150 (lowest)
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif  // BUREAUCRAT_EX01_HPP_