/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) { 
  try {
    std::cout << GREEN << "\n------- TEST 1 (CORRECT INPUT) -------\n"
              << RESET << std::endl;
    Bureaucrat ant_man("Ant-Man", 50);
    Form certificate;
    Form diploma("Diploma", 49, 50);

    std::cout << "\n" << ant_man << "\n" << std::endl;
    std::cout << certificate << "\n" << std::endl;
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call Bureaucrat::signForm():" << std::endl;
    ant_man.signForm(certificate);
    std::cout << certificate << "\n" << std::endl;
    std::cout << "Tried sign once again:" << std::endl;
    ant_man.signForm(certificate);
    std::cout << std::endl;
    ant_man.signForm(diploma);
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  std::cout << GREEN << "\n------- TEST 2 (INVALID FORM) -------\n\n";
  try {
    std::cout << GREEN << "---> Grade to sign = 0:"
              << RESET << std::endl;
    Form diploma("Diploma", 0, 50);
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "---> Grade to sign = 151:"
              << RESET << std::endl;
    Form diploma("Diploma", 151, 50);
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "---> Grade to execute = 0:"
              << RESET << std::endl;
    Form diploma("Diploma", 50, 0);
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "---> Grade to execute = 151:"
              << RESET << std::endl;
    Form diploma("Diploma", 50, 151);
    std::cout << diploma << "\n" << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  return 0;
}