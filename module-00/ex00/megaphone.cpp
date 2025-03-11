/**
 * @file megaphone.cpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @brief Print the given arguments in capslock
 * @version 0.1
 * @date 2025-03-11
 */

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  int i = 1;
  while (argv[i] != NULL) {
    for (int j = 0; argv[i][j] != '\0'; j++) argv[i][j] = toupper(argv[i][j]);
    std::cout << argv[i];
    i++;
  }
  std::cout << std::endl;
  return 0;
}