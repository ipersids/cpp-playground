/**
 * @file Contact.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-11
 */

#pragma once

#include <iostream>

class Contact {
 public:
  Contact();
  Contact(Contact& contact) = delete;
  Contact& operator=(const Contact& contact);
  ~Contact() = default;

  void getContactInfo(void);
  std::string getName() const;
  std::string getLastName() const;
  std::string getNick() const;
  std::string getNumber() const;
  std::string getSecret() const;

 private:
  std::string _name;
  std::string _lastname;
  std::string _nick;
  std::string _number;
  std::string _secret;
};
