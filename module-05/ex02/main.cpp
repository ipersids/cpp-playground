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

int main(void) {
  try {
    std::cout << GREEN << "\n------- TEST 1 (ShrubberyCreationForm) -------\n"
              << RESET << std::endl;
    Bureaucrat groot("Groot", 120);
    ShrubberyCreationForm home;
    ShrubberyCreationForm forest("forest");

    std::cout << "\n" << groot << "\n" << std::endl;
    home.beSigned(groot);
    std::cout << home << "\n" << std::endl;
    std::cout << forest << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    home.execute(groot);
    forest.execute(groot);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 2 (ShrubberyCreationForm) -------\n"
              << RESET << std::endl;
    Bureaucrat gamora("Gamora", 146);
    ShrubberyCreationForm space("space");

    std::cout << "\n" << gamora << "\n" << std::endl;
    std::cout << space << "\n" << std::endl;
    space.beSigned(gamora);
    std::cout << space << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    space.execute(gamora);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 3 (ShrubberyCreationForm) -------\n"
              << RESET << std::endl;
    Bureaucrat gamora("Gamora", 138);
    ShrubberyCreationForm space("space");

    std::cout << "\n" << gamora << "\n" << std::endl;
    std::cout << space << "\n" << std::endl;
    space.beSigned(gamora);
    std::cout << space << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    space.execute(gamora);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 4 (RobotomyRequestForm) -------\n"
              << RESET << std::endl;
    Bureaucrat star_lord("Star-Lord", 45);
    RobotomyRequestForm galaxy("galaxy");
    RobotomyRequestForm space_ship("space_ship");

    std::cout << "\n" << star_lord << "\n" << std::endl;
    galaxy.beSigned(star_lord);
    std::cout << galaxy << "\n" << std::endl;
    std::cout << space_ship << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    std::srand(std::time(nullptr));
    for (int i = 0; i < 10; i++) {
      std::cout << "[" << i << "] >> ";
      galaxy.execute(star_lord);
      std::cout << std::endl;
    }

    std::cout << "Tried execute " << space_ship.getName() << ":" << std::endl;
    space_ship.execute(star_lord);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 5 (RobotomyRequestForm) -------\n"
              << RESET << std::endl;
    Bureaucrat star_lord("Star-Lord", 73);
    RobotomyRequestForm space_ship("space_ship");

    std::cout << "\n" << star_lord << "\n" << std::endl;
    std::cout << space_ship << "\n\nTried to sign:" << std::endl;
    space_ship.beSigned(star_lord);
    std::cout << space_ship << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    space_ship.execute(star_lord);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 6 (RobotomyRequestForm) -------\n"
              << RESET << std::endl;
    Bureaucrat star_lord("Star-Lord", 46);
    RobotomyRequestForm space_ship("space_ship");

    std::cout << "\n" << star_lord << "\n" << std::endl;
    std::cout << space_ship << "\n\nTried to sign:" << std::endl;
    space_ship.beSigned(star_lord);
    std::cout << space_ship << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    space_ship.execute(star_lord);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 7 (PresidentialPardonForm) -------\n"
              << RESET << std::endl;
    Bureaucrat deadpool("Deadpool", 1);
    PresidentialPardonForm rocket;
    PresidentialPardonForm deadpools_dark_humor("deadpools_dark_humor");

    std::cout << "\n" << deadpool << "\n" << std::endl;
    rocket.beSigned(deadpool);
    std::cout << rocket << "\n" << std::endl;
    std::cout << deadpools_dark_humor << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    rocket.execute(deadpool);

    std::cout << "\nTried execute " << deadpools_dark_humor.getName() << ":"
              << std::endl;
    deadpools_dark_humor.execute(deadpool);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 8 (PresidentialPardonForm) -------\n"
              << RESET << std::endl;
    Bureaucrat deadpool("Deadpool", 26);
    PresidentialPardonForm deadpools_dark_humor("deadpools_dark_humor");

    std::cout << "\n" << deadpool << "\n" << std::endl;
    std::cout << deadpools_dark_humor << "\n\nTried to sign:" << std::endl;
    deadpools_dark_humor.beSigned(deadpool);
    std::cout << deadpools_dark_humor << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    deadpools_dark_humor.execute(deadpool);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 9 (PresidentialPardonForm) -------\n"
              << RESET << std::endl;
    Bureaucrat deadpool("Deadpool", 6);
    PresidentialPardonForm deadpools_dark_humor("deadpools_dark_humor");

    std::cout << "\n" << deadpool << "\n" << std::endl;
    std::cout << deadpools_dark_humor << "\n\nTried to sign:" << std::endl;
    deadpools_dark_humor.beSigned(deadpool);
    std::cout << deadpools_dark_humor << "\n" << std::endl;

    std::cout << "\n---> Call execute():" << std::endl;
    deadpools_dark_humor.execute(deadpool);

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  return 0;
}