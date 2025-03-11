/**
 * @file PhoneBook.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-11
 */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
  _index = 0;
  for (Contact& c : _contacts) {
    c = Contact();
  }
}

void PhoneBook::addContact(Contact& contact) {
  _contacts[_index++ % CAPACITY] = contact;
}

void PhoneBook::displayContacts() const {
  std::cout << std::setw(10) << "Index"
            << "|" << std::setw(10) << "First Name"
            << "|" << std::setw(10) << "Last Name"
            << "|" << std::setw(10) << "Nickname"
            << std::endl;
  for (int i = 0; i < CAPACITY; ++i) {
    if (_contacts[i].getName() != "Uknown") {
      std::cout << std::setw(10) << i << "|" << std::setw(10)
                << makeShorter(_contacts[i].getName()) << "|" << std::setw(10)
                << makeShorter(_contacts[i].getLastName()) << "|"
                << std::setw(10) << makeShorter(_contacts[i].getNick())
                << std::endl;
    }
  }
  int index = -1;
  while (true) {
    std::cout << "Enter index: ";
    std::cin >> index;
    if (index < 0 || index >= CAPACITY || std::cin.fail()) {
      std::cout << "Error: index should be in range from 0 to " << CAPACITY
                << "." << std::endl;
    } else if (index >= _index) {
      std::cout << "Error: contact with index " << index << " is empty."
                << std::endl;
    } else {
      std::cout << "Name:\t\t" << _contacts[index].getName()
                << std::endl;
      std::cout << "Last Name:\t" << _contacts[index].getLastName()
                << std::endl;
      std::cout << "Nickname:\t" << _contacts[index].getNick()
                << std::endl;
      std::cout << "Phone Number:\t" << _contacts[index].getNumber()
                << std::endl;
      std::cout << "Dark Secret:\t" << _contacts[index].getSecret()
                << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    break;
  }
}

std::string PhoneBook::makeShorter(std::string str) const {
  if (str.length() > SHOWN_LEN) {
    return str.substr(0, SHOWN_LEN - 1) + ".";
  }
  return str;
}