/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-11
 */

#include <Array.hpp>
#include <iostream>

#define MAX_VAL 750

int main(int, char**) {
  std::cout << "----------- TEST 1 (CREATE ARRAYS) -----------\n" << std::endl;
  Array<int> numbers(MAX_VAL);
  int* mirror = new int[MAX_VAL];

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = i;
    mirror[i] = i;
    if (i < 10) {
      std::cout << "Before: numbers[" << i << "] = " << numbers[i] << std::endl;
      std::cout << "Before: mirror[" << i << "] = " << mirror[i] << "\n"
                << std::endl;
    }
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      delete[] mirror;
      return 1;
    }
  }

  // SCOPE
  std::cout << "\n--------------- TEST 2 (SCOPE) ---------------\n"
            << std::endl;
  {
    Array<int> tmp = numbers;
    for (int i = 0; i < 10; i++) {
      std::cout << "Copy of numbers: tmp[" << i << "] = " << tmp[i]
                << ((numbers[i] == tmp[i]) ? " (true)" : " (false)")
                << std::endl;
    }
    Array<int> test(tmp);
  }

  std::cout << "\n------------ TEST 3 (EXCEPTIONS) -------------\n"
            << std::endl;

  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << std::endl;
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  std::cout << std::endl;

  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
    if (i < 10) {
      std::cout << "After: numbers[" << i << "] = " << numbers[i] << std::endl;
      std::cout << "After: mirror[" << i << "] = " << mirror[i] << "\n"
                << std::endl;
    }
  }

  std::cout << "\n-------------- TEST 5 (SIZE()) ---------------\n"
            << std::endl;

  Array<int> empty_arr;
  std::cout << "empty_arr.size() = " << empty_arr.size() << std::endl;
  std::cout << "numbers.size() = " << numbers.size() << std::endl;
  std::cout << "MAX_VAL = " << MAX_VAL << std::endl;

  std::cout << "\n---------------- DESTRUCTORS -----------------\n"
            << std::endl;
  delete[] mirror;
  return 0;
}