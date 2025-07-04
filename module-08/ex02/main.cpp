#include <cassert>
#include <iostream>

#include "MutantStack.hpp"

#define GREEN "\033[32m"

int main(void) {
  MutantStack<int> default_stack;

  std::cout << "\nStack with default constructor created:"
            << "\n - size(): " << default_stack.size()
            << "\n - empty(): " << (default_stack.empty() ? "true" : "false")
            << std::endl;

  std::cout << "\nPush integers from 0 to 14: " << std::endl;
  for (int i = 0; i < 15; ++i) {
    default_stack.push(i);
  }
  size_t default_stack_size = default_stack.size();
  std::cout << " - new size: " << default_stack_size << std::endl;

  std::cout << "\nIterate and print content: \n [ " << std::flush;
  for (auto it = default_stack.begin(), end = default_stack.end(); it != end;
       ++it) {
    std::cout << *it << " " << std::flush;
  }
  std::cout << " ]" << std::endl;

  int default_stack_top = default_stack.top();

  std::cout << "\nPerform operations: "
            << "\n - top(): " << default_stack_top << "\n - pop(): ";
  default_stack.pop();
  assert(default_stack_size - 1 == default_stack.size());
  std::cout << "success (new size = " << default_stack.size() << ")"
            << "\n - push(): ";
  default_stack.push(default_stack_top + 1);
  assert(default_stack_size == default_stack.size());
  std::cout << "success (new size = " << default_stack.size() << ")"
            << std::endl;

  std::cout << "\nIterate and print content: \n [ " << std::flush;
  for (auto it = default_stack.begin(), end = default_stack.end(); it != end;
       ++it) {
    std::cout << *it << " " << std::flush;
  }
  std::cout << " ]" << std::endl;

  std::cout << "\nCopy current stack using copy constructor: " << std::endl;
  MutantStack<int> copy_stack(default_stack);
  assert(copy_stack == default_stack);
  std::cout << " [ " << std::flush;
  for (auto it = copy_stack.begin(), end = copy_stack.end(); it != end; ++it) {
    std::cout << *it << " " << std::flush;
    *it += 15;  // changing after checking
  }
  std::cout << " ]" << std::endl;

  copy_stack.pop();
  assert(default_stack.size() > copy_stack.size());

  std::cout << "\nCreate const stack and use const iterators: " << std::endl;
  const MutantStack<int> constant_stack(copy_stack);
  std::cout << " [ " << std::flush;
  for (auto it = constant_stack.begin(), end = constant_stack.end(); it != end;
       ++it) {
    std::cout << *it << " " << std::flush;
    // *it = 45; // compilation error
  }
  std::cout << " ]" << std::endl;

  std::cout << GREEN "\nAll tests passed\n" << std::endl;

  return 0;
}