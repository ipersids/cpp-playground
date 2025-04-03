/**
 * @file ShrubberyCreationForm.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef SHRUBBERYCREATIONFORM_EX02_HPP_
#define SHRUBBERYCREATIONFORM_EX02_HPP_

#include <fstream>
#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  // https://en.cppreference.com/w/cpp/language/default_constructor
  ShrubberyCreationForm(const std::string& target = "home");
  ShrubberyCreationForm(const ShrubberyCreationForm& other) = delete;
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other) = delete;
  ~ShrubberyCreationForm() override;

  void execute(Bureaucrat const& executor) const override;
};

#endif  // SHRUBBERYCREATIONFORM_EX02_HPP_