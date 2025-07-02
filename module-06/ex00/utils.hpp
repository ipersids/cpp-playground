#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

/* ----------------- DISPLAY RESULT ---------------- */

void displayError(const std::string& ch, const std::string& i, const std::string& f, const std::string& d);

/* ---------------- CHECK DATA TYPE ---------------- */

bool isChar(const std::string& literal);
bool isIntenger(const std::string& literal);
bool isFloat(const std::string& literal);
bool isDouble(const std::string& literal);

/* ----------------- TRY TO CONVERT ----------------- */

int tryToIntenger(const std::string& literal);
float tryToFloat(const std::string& literal);
double tryToDouble(const std::string& literal);

/* ------------------ CALCULATIONS ------------------ */
