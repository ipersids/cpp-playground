/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void) {
  try {
    Intern random_intern;

    std::cout << GREEN << "\n------- TEST 1 (robotomy request) -------\n"
              << RESET << std::endl;
    AForm* rrf;
    rrf = random_intern.makeForm("robotomy request", "Mr. Fantastic");
    if (rrf != nullptr) {
      std::cout << "\n" << *rrf << "\n" << std::endl;
      delete rrf;
    }
    std::cout << std::endl;

    std::cout << GREEN << "\n------- TEST 2 (shrubbery creation) -------\n"
              << RESET << std::endl;
    AForm* scf;
    scf = random_intern.makeForm("shrubbery creation", "InvisibleWoman");
    if (scf != nullptr) {
      std::cout << "\n" << *scf << "\n" << std::endl;
      delete scf;
    }
    std::cout << std::endl;

    std::cout << GREEN << "\n------- TEST 3 (presidential pardon) -------\n"
              << RESET << std::endl;
    AForm* ppf;
    ppf = random_intern.makeForm("presidential pardon", "Human Torch");
    if (ppf != nullptr) {
      std::cout << "\n" << *ppf << "\n" << std::endl;
      delete ppf;
    }
    std::cout << std::endl;

    std::cout << GREEN << "\n------- TEST 3 (uknown request) -------\n"
              << RESET << std::endl;
    AForm* uknownf;
    uknownf = random_intern.makeForm("uknown request", "The Thing");
    if (uknownf != nullptr) {
      std::cout << "\n" << *scf << "\n" << std::endl;
      delete uknownf;
    }
    std::cout << std::endl;

  }
    catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  return 0;
}