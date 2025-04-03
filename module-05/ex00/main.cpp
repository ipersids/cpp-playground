/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
  try {
    std::cout << GREEN << "\n---------- TEST 1 (CORRECT GRADE) ----------\n"
              << RESET << std::endl;
    Bureaucrat dr_strange;
    Bureaucrat cp_marvel("Captain Marvel", 1);
    Bureaucrat spider_man("Spider-Man", 150);
    Bureaucrat hulk("Hulk", 66);

    std::cout << "\n---> Call getters:" << std::endl;
    std::cout << "-getName(): " << dr_strange.getName() << std::endl;
    std::cout << "-getGrade(): " << dr_strange.getGrade() << std::endl;

    std::cout << "\n---> Call << operator:" << std::endl;
    std::cout << dr_strange << std::endl;
    std::cout << cp_marvel << std::endl;
    std::cout << spider_man << std::endl;
    std::cout << hulk << std::endl;

    std::cout << "\n---> Call incrementGrade():" << std::endl;
    std::cout << "Increment " << hulk.getName()
              << " grade 10 times:" << std::endl;
    for (int i = 0; i < 10; i++) {
      std::cout << "\t- [" << i + 1 << "] -> ";
      hulk.incrementGrade();
      std::cout << hulk << std::endl;
    }

    std::cout << "\n---> Call decrementGrade():" << std::endl;
    std::cout << "Decrement " << hulk.getName()
              << " grade 10 times:" << std::endl;
    for (int i = 0; i < 10; i++) {
      std::cout << "\t- [" << i + 1 << "] -> ";
      hulk.decrementGrade();
      std::cout << hulk << std::endl;
    }

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n--------- TEST 2 (TOO HIGH GRADE) ----------\n"
              << RESET << std::endl;
    Bureaucrat black_widow("Black Widow", 0);

    std::cout << "\n---> Call getters:" << std::endl;
    std::cout << "-getName(): " << black_widow.getName() << std::endl;
    std::cout << "-getGrade(): " << black_widow.getGrade() << std::endl;

    std::cout << "\n---> Call << operator:" << std::endl;
    std::cout << black_widow << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n--------- TEST 3 (TOO LOW GRADE) ----------\n"
              << RESET << std::endl;
    Bureaucrat iron_man("Iron Man", 151);

    std::cout << "\n---> Call getters:" << std::endl;
    std::cout << "-getName(): " << iron_man.getName() << std::endl;
    std::cout << "-getGrade(): " << iron_man.getGrade() << std::endl;

    std::cout << "\n---> Call << operator:" << std::endl;
    std::cout << iron_man << std::endl;

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 4 (INCREMENT EXCEPTION) -------\n"
              << RESET << std::endl;
    Bureaucrat black_panther("Black Panther", 1);
    std::cout << black_panther << std::endl;
    black_panther.incrementGrade();

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  try {
    std::cout << GREEN << "\n------- TEST 5 (DECREMENT EXCEPTION) -------\n"
              << RESET << std::endl;
    Bureaucrat thor("Thor", 150);
    std::cout << thor << std::endl;
    thor.decrementGrade();

    std::cout << "\n---> Call destructors:" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << RED << e.what() << RESET << std::endl;
  }

  return 0;
}