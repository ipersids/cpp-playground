/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-03-22
 */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void testDog() {
  std::cout << "\n--- Testing dog constructor ---" << std::endl;
  Dog dog1;
  dog1.setIdea(0, "Find a human.");
  std::cout << "dog1 idea 0: " << BLUE << dog1.getIdea(0) << RESET << std::endl;

  std::cout << "\n--- Testing dog copy constructor ---" << std::endl;
  Dog dog2 = dog1;
  std::cout << "dog2 (deep copy) idea 0: " << BLUE << dog2.getIdea(0) << RESET
            << std::endl;

  std::cout << "\n--- Testing dog assignment operator ---" << std::endl;
  Dog dog3;
  dog3 = dog1;
  std::cout << "dog3 (deep copy) idea 0: " << BLUE << dog3.getIdea(0) << RESET
            << std::endl;

  std::cout << "\n--- Testing dog destructor ---" << std::endl;
}

void testCat() {
  std::cout << "\n--- Testing cat constructor ---" << std::endl;
  Cat cat1;
  cat1.setIdea(0, "Avoid a human.");
  std::cout << "cat1 idea 0: " << GREEN << cat1.getIdea(0) << RESET
            << std::endl;

  std::cout << "\n--- Testing cat copy constructor ---" << std::endl;
  Cat cat2 = cat1;
  std::cout << "cat2 (deep copy) idea 0: " << GREEN << cat2.getIdea(0) << RESET
            << std::endl;

  std::cout << "\n--- Testing cat assignment operator ---" << std::endl;
  Cat cat3;
  cat3 = cat1;
  std::cout << "cat3 (deep copy) idea 0: " << GREEN << cat3.getIdea(0) << RESET
            << std::endl;

  std::cout << "\n--- Testing cat destructor ---" << std::endl;
}

int main(void) {
  std::cout << "\n------------------------ TEST 1 ------------------------\n"
            << std::endl;
  testDog();
  std::cout << "\n------------------------ TEST 2 ------------------------\n"
            << std::endl;
  testCat();
  std::cout << "\n------------------------ TEST 3 ------------------------\n"
            << std::endl;
  {
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;  // should not create a leak
    delete i;
  }
  std::cout << "\n------------------------ TEST 4 ------------------------\n"
            << std::endl;
  {
    const int size = 4;
    Animal* animals[size];

    std::cout << "\n--- Creating animals ---" << std::endl;

    for (int i = 0; i < size / 2; ++i) {
      animals[i] = new Dog();
      animals[i]->makeSound();
    }
    for (int i = size / 2; i < size; ++i) {
      animals[i] = new Cat();
      animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting animals ---" << std::endl;

    for (int i = 0; i < size; ++i) {
      delete animals[i];
    }
  }
  return 0;
}