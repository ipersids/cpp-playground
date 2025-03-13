/**
 * @file replace.cpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#include "replace.hpp"

bool is_args_valid(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << "Usage: ./exe_replace <file_name> <string_to_be_replaced> "
                 "<new_string>"
              << std::endl;
    return false;
  }

  std::string open_file_name = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];

  if (open_file_name.empty() || s1.empty() || s2.empty()) {
    std::cerr << "Error: arguments cannot be empty" << std::endl;
    return false;
  }

  return true;
}

bool is_fstreams_ready(const std::string file_name, std::fstream* fin,
                       std::fstream* fout) {
  fin->open(file_name, std::fstream::in);
  if (fin->is_open() == false) {
    std::cerr << "Error: opening file " << file_name << std::endl;
    return false;
  }

  fout->open(file_name + ".replace", std::fstream::out);
  if (fout->is_open() == false) {
    fin->close();
    std::cerr << "Error: opening file " << file_name + ".replace" << std::endl;
    return false;
  }

  return true;
}

bool replace(std::fstream* fin, std::fstream* fout, const std::string s1,
             const std::string s2) {
  std::string content((std::istreambuf_iterator<char>(*fin)),
                      std::istreambuf_iterator<char>());
  if (fin->bad()) {
    std::cerr << "Error occurred while reading file" << std::endl;
    fout->close();
    fin->close();
    return false;
  }

  size_t start = 0;
  size_t found = 0;
  size_t s1_len = s1.length();
  std::string result = "";

  found = content.find(s1, start);
  while (found != std::string::npos) {
    result.append(content, start, found - start);
    result.append(s2);
    *fout << result;

    if (fout->fail()) {
      std::cerr << "Error: failed to write to the file" << std::endl;
      fout->close();
      fin->close();
      return false;
    }

    result.clear();
    start = found + s1_len;
    found = content.find(s1, start);
  }

  result.append(content, start, content.length() - start);
  *fout << result;
  if (fout->fail()) {
    std::cerr << "Error: failed to write to the file" << std::endl;
    fout->close();
    fin->close();
    return false;
  }

  fout->close();
  fin->close();
  return true;
}