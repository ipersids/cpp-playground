/**
 * @file main.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-10
 */

#include <iostream>

#include "iter.hpp"

int main(void) {
  std::cout << "-------------- TEST 1: Array of integers --------------\n"
            << std::endl;
  int arr_int[] = {1, 2, 3, 4, 5, 6};
  int arr_int_len = sizeof(arr_int) / sizeof(arr_int[0]);
  std::cout << "Print array: " << std::endl;
  iter(arr_int, arr_int_len, print_test<int>);
  std::cout << "\nAdd 2 to each element and print array: " << std::endl;
  iter(arr_int, arr_int_len, add_const_test<int>);
  iter(arr_int, arr_int_len, print_test<int>);

  std::cout << "\n\n--------------- TEST 2: Array of doubles --------------\n"
            << std::endl;
  double arr_double[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
  int arr_double_len = sizeof(arr_double) / sizeof(arr_double[0]);
  std::cout << "print array: " << std::endl;
  iter(arr_double, arr_double_len, print_test<double>);
  std::cout << "\nAdd 2 to each element and print array: " << std::endl;
  iter(arr_double, arr_double_len, add_const_test<double>);
  iter(arr_double, arr_double_len, print_test<double>);

  std::cout << "\n\n--------------- TEST 3: Array of strings --------------\n"
            << std::endl;
  std::string arr_string[] = {"hello", "there", "wow!"};
  int arr_string_len = sizeof(arr_string) / sizeof(arr_string[0]);
  std::cout << "print array: " << std::endl;
  iter(arr_string, arr_string_len, print_test<std::string>);

  std::cout
      << "\n\n------------- TEST 4: Const array of integers -------------\n"
      << std::endl;
  const int const_arr_int[] = {1, 2, 3, 4, 5, 6};
  int const_arr_int_len = sizeof(const_arr_int) / sizeof(const_arr_int[0]);
  std::cout << "Print array: " << std::endl;
  iter(const_arr_int, const_arr_int_len, print_test<const int>);
}