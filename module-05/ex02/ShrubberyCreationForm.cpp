/**
 * @file ShrubberyCreationForm.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm(target + "_shrubbery", 145, 137) {
  std::cout << "ShrubberyCreationForm: default constructor with a parameter "
               "list called"
            << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm: destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  this->checkRightToExecute(executor);
  std::ofstream shrubbery(this->getName());
  if (shrubbery.is_open() == false) {
    std::cerr << RED << "Error: can't open the file '" << this->getName() << "'"
              << RESET << std::endl;
    throw;
  }

  std::string forest = R"(
               ,@@@@@@@,
       ,,,.   ,@@@@@@/@@,  .oo8888o.
    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
   %&&%&%&/%&&%@@\@@/ /@@@88888\88888'
   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
   `&%\ ` /%&'    |.|        \ '|8'
       |o|        | |         | |
       |.|        | |         | |
hey \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_
  )";

  shrubbery << forest;
  shrubbery.close();
  std::cout << "ShrubberyCreationForm: file " << MAGENTA
            << "'" + this->getName() + "'" << RESET << " successfully created"
            << std::endl;
}