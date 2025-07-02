#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void) {
  int check = rand() % 3;
  try {
    if (check == 0) {
      std::cout << "Random: " << CYAN << "A" << RESET << " class generated"
                << std::endl;
      A* a = new A();
      return a;
    }
    if (check == 1) {
      std::cout << "Random: " << BLUE << "B" << RESET << " class generated"
                << std::endl;
      B* b = new B();
      return b;
    }
    if (check == 2) {
      std::cout << "Random: " << MAGENTA << "C" << RESET << " class generated"
                << std::endl;
      C* c = new C();
      return c;
    }
  } catch (...) {
    std::cerr << RED << "Error: " << RESET
              << "Memory allocation with new() failed" << std::endl;
    std::exit(1);
  }
  return nullptr;
}

void Base::identify(Base* p) {
  A* a = dynamic_cast<A*>(p);
  if (a != nullptr) {
    std::cout << "Class type for pointer: " << CYAN << "A" << RESET
              << std::endl;
    return;
  }
  B* b = dynamic_cast<B*>(p);
  if (b != nullptr) {
    std::cout << "Class type for pointer: " << BLUE << "B" << RESET
              << std::endl;
    return;
  }
  C* c = dynamic_cast<C*>(p);
  if (c != nullptr) {
    std::cout << "Class type for pointer: " << MAGENTA << "C" << RESET
              << std::endl;
    return;
  }
  std::cout << "Class type for pointer: " << RED << "undefined" << RESET
            << std::endl;
}

void Base::identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    (void)a;
    std::cout << "Class type for reference: " << CYAN << "A" << RESET
              << std::endl;
    return;
  } catch (...) {
  }
  try {
    B& b = dynamic_cast<B&>(p);
    (void)b;
    std::cout << "Class type for reference: " << BLUE << "B" << RESET
              << std::endl;
    return;
  } catch (...) {
  }
  try {
    C& c = dynamic_cast<C&>(p);
    (void)c;
    std::cout << "Class type for reference: " << MAGENTA << "C" << RESET
              << std::endl;
    return;
  } catch (...) {
  }
  std::cout << "Class type for reference: " << RED << "undefined" << RESET
            << std::endl;
}
