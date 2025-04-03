/**
 * @file RobotomyRequestForm.hpp
 * Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-03
 */

#ifndef ROBOTOMYREQUESTFORM_EX02_HPP_
#define ROBOTOMYREQUESTFORM_EX02_HPP_

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string& target = "answer_of_everything");
  RobotomyRequestForm(const RobotomyRequestForm& other) = delete;
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other) = delete;
  ~RobotomyRequestForm() override;

  void execute(Bureaucrat const& executor) const override;
};

#endif  // ROBOTOMYREQUESTFORM_EX02_HPP_