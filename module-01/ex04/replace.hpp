/**
 * @file replace.hpp
 * @author Julia Persidskaia
 * @date 2025-03-13
 */

#ifndef REPLACE_EX04_HPP_
#define REPLACE_EX04_HPP_

#include <fstream>
#include <iostream>

bool is_args_valid(int argc, char** argv);
bool is_fstreams_ready(const std::string file_name, std::fstream* in,
                       std::fstream* out);
bool replace(std::fstream* fin, std::fstream* out, const std::string s1,
             const std::string s2);

#endif  // REPLACE_EX04_HPP_