/**
 * @file PresidentialPardonForm.hpp
 * @author @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef PRESIDENTIALPARDONFORM_EX02_HPP_
#define PRESIDENTIALPARDONFORM_EX02_HPP_

#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string& target = "Rocket Raccoon");
  PresidentialPardonForm(const PresidentialPardonForm& other) = delete;
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other) =
      delete;
  ~PresidentialPardonForm() override;

  void execute(Bureaucrat const& executor) const override;
};

#endif  // PRESIDENTIALPARDONFORM_EX02_HPP_