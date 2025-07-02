#pragma once

#include <cstdlib>
#include <iostream>

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#endif  // COLORS

class A;
class B;
class C;

class Base {
 public:
  virtual ~Base() = default;

  Base* generate(void);
  void identify(Base* p);
  void identify(Base& p);
};
