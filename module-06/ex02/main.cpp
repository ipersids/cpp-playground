#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

int main(void) {
  A base;
  srand(time(NULL));
  for (int i = 0; i < 15; i++) {
    std::cout << GREEN << "\nTest " << i << ": " << RESET << std::endl;
    Base* test = base.generate();
    Base& ref_test = *test;
    base.identify(test);
    base.identify(ref_test);
    delete test;
  }
  return 0;
}