/**
 * @file RobotomyRequestForm.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm(target, 72, 45) {
  std::cout << "RobotomyRequestForm: default constructor with a parameter "
            << "list called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm: destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  this->checkRightToExecute(executor);
  if (std::rand() % 2 == 0) {
    std::cout << "* DRILLING NOISES HERE ⸜(｡˃ ᵕ ˂ )⸝♡ *" << std::endl;
    std::cout << MAGENTA << this->getName() << RESET
              << ": was successfully robotomized" << std::endl;
  } else {
    std::cout << RED << this->getName() << ": robotomy failed" << RESET
              << std::endl;
  }
}