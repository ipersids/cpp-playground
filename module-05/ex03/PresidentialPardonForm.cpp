/**
 * @file PresidentialPardonForm.cpp
 * @author @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm(target, 25, 5) {
  std::cout << "PresidentialPardonForm: default constructor with a parameter "
            << "list called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm: destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  this->checkRightToExecute(executor);
  std::cout << MAGENTA << this->getName() << RESET
            << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}