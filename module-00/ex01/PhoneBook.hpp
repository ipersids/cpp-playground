/**
 * @file PhoneBook.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-11
 */

#pragma once

#include <iomanip>
#include <iostream>

#include "Contact.hpp"

#define CAPACITY 8
#define SHOWN_LEN 10

class PhoneBook {
 public:
  PhoneBook();
  PhoneBook(PhoneBook& book) = delete;
  PhoneBook& operator=(const PhoneBook& book) = delete;
  ~PhoneBook() = default;

  void addContact(Contact& contact);
  void displayContacts(void) const;

 private:
  int _index;
  Contact _contacts[CAPACITY];
  std::string makeShorter(const std::string str) const;
};
