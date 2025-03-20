/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string* stringPTR = &str;
  std::string& stringREF = str;

  std::cout << "The memory address of the string variable:\t" << &str
            << "\nThe memory address held by stringPTR:\t\t" << stringPTR
            << "\nThe memory address held by stringREF:\t\t" << &stringREF
            << std::endl;

  std::cout << "\nThe value of the string variable:\t\t" << str
            << "\nThe value pointed to by stringPTR:\t\t" << *stringPTR
            << "\nThe value pointed to by stringREF:\t\t" << stringREF
            << std::endl;
}