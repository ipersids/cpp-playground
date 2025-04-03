/**
 * @file Intern.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

 #ifndef INTERN_EX03_HPP_
 #define INTERN_EX03_HPP_

 #include "RobotomyRequestForm.hpp"
 #include "ShrubberyCreationForm.hpp"
 #include "PresidentialPardonForm.hpp"

 #include <iostream>

 #define FORMS_AMOUNT 3

class Intern {
  public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& form_name, const std::string& target);
};


 #endif // INTERN_EX03_HPP_