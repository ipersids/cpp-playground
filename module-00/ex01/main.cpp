/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-11
 */

#include <iostream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
  std::string input;
  Contact contact;
  PhoneBook book;

  while (true) {
    std::cout << "PhoneBook> ";
    if (!std::getline(std::cin, input)) {
      std::cin.clear();
      freopen("/dev/tty", "r", stdin);
      std::cout << std::endl;
      continue;
    }

    if (input.empty()) {
      continue;
    }

    if (input == "EXIT") {
      break;
    }
    if (input == "ADD") {
      contact.getContactInfo();
      book.addContact(contact);
      std::cout << "Contact was added." << std::endl;
      continue;
    }
    if (input == "SEARCH") {
      book.displayContacts();
    }
  }
}