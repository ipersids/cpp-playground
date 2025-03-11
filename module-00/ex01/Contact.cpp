/**
 * @file Contact.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-11
 */

#include "Contact.hpp"

Contact::Contact() {
  _name = "Uknown";
  _lastname = "Uknown";
  _nick = "Uknown";
  _number = "Uknown";
  _secret = "Uknown";
}

Contact& Contact::operator=(const Contact& contact) {
  if (this != &contact) {
    this->_name = contact._name;
    this->_lastname = contact._lastname;
    this->_nick = contact._nick;
    this->_number = contact._number;
    this->_secret = contact._secret;
  }
  return *this;
}

void Contact::getContactInfo() {
  while (true) {
    std::cout << "Enter name: ";
    std::getline(std::cin, _name);
    if (_name.empty()) {
      std::cout << "Error: field could not be empty." << std::endl;
      continue;
    }
    break;
  }
  while (true) {
    std::cout << "Enter lastname: ";
    std::getline(std::cin, _lastname);
    if (_lastname.empty()) {
      std::cout << "Error: field could not be empty." << std::endl;
      continue;
    }
    break;
  }
  while (true) {
    std::cout << "Enter nickname: ";
    std::getline(std::cin, _nick);
    if (_nick.empty()) {
      std::cout << "Error: field could not be empty." << std::endl;
      continue;
    }
    break;
  }
  while (true) {
    std::cout << "Enter number: ";
    std::getline(std::cin, _number);
    if (_number.empty()) {
      std::cout << "Error: field could not be empty." << std::endl;
      continue;
    }
    break;
  }
  while (true) {
    std::cout << "Enter secret: ";
    std::getline(std::cin, _secret);
    if (_secret.empty()) {
      std::cout << "Error: field could not be empty." << std::endl;
      continue;
    }
    break;
  }
}

std::string Contact::getName() const { return _name; }

std::string Contact::getLastName() const { return _lastname; }

std::string Contact::getNick() const { return _nick; }

std::string Contact::getNumber() const { return _number; }

std::string Contact::getSecret() const { return _secret; }