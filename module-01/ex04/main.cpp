/**
 * @file main.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include <fstream>
#include <iostream>

#include "replace.hpp"

int main(int argc, char** argv) {
  if (!is_args_valid(argc, argv)) {
    return 1;
  }

  std::string file_name = argv[1];
  std::fstream fin;
  std::fstream fout;
  if (!is_fstreams_ready(file_name, &fin, &fout)) {
    return 1;
  }

  std::string s1 = argv[2];
  std::string s2 = argv[3];
  if (!replace(&fin, &fout, s1, s2)) {
    return 1;
  }

  return 0;
}