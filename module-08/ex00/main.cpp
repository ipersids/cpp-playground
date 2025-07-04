#include <array>
#include <cassert>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

template <typename Container>
void test_container(Container container, const Container const_container,
                    const std::string& container_name, int search_value,
                    int missing_value) {
  std::cout << "\n ================= " << container_name
            << " ================= " << std::endl
            << std::endl;

  std::cout << BLUE << "  Test non-const container: " << RESET << std::endl;
  try {
    auto& found = easyfind(container, search_value);
    std::cout << "  Found value: " << std::flush;
    assert(found == search_value);
    std::cout << MAGENTA << found << RESET << std::endl;

    auto original = found;
    std::cout << "  Modify value (reference check): " << std::flush;
    found = 999;
    auto& found_again = easyfind(container, 999);
    assert(found_again == 999);
    std::cout << MAGENTA << found_again << RESET << std::endl;

    // reset value
    found_again = original;

  } catch (const std::exception& e) {
    std::cout << "  Unexpected exception: " << e.what() << std::endl;
  }

  std::cout << BLUE << "  Test const container: " << RESET << std::endl;
  try {
    const auto& found = easyfind(const_container, search_value);
    std::cout << "  Found value: " << std::flush;
    assert(found == search_value);
    std::cout << MAGENTA << found << RESET << std::endl;
  } catch (const std::exception& e) {
    std::cout << "  Unexpected exception: " << e.what() << std::endl;
  }

  std::cout << BLUE << "  Test exception for missing value: " << RESET
            << std::endl;
  try {
    easyfind(container, missing_value);
    assert(false && (RED "Should have thrown exception"));
  } catch (const std::out_of_range& e) {
    std::cout << GREEN << "  Exception caught correctly: " << RESET << e.what()
              << std::endl;
  }

  std::cout << "\n Result: " << GREEN << "SUCCESS " << RESET << std::endl;
}

int main(void) {
  try {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    const std::vector<int> const_vec = {1, 2, 3, 4, 5};
    test_container(vec, const_vec, "std::vector", 3, 99);

    std::list<int> lst = {10, 20, 30, 40, 50};
    const std::list<int> const_lst = {10, 20, 30, 40, 50};
    test_container(lst, const_lst, "std::list", 30, 999);

    std::deque<int> dq = {5, 10, 15, 20, 25};
    const std::deque<int> const_dq = {5, 10, 15, 20, 25};
    test_container(dq, const_dq, "std::deque", 15, 100);

    std::array<int, 5> arr = {2, 4, 6, 8, 10};
    const std::array<int, 5> const_arr = {2, 4, 6, 8, 10};
    test_container(arr, const_arr, "std::array", 6, 50);

    std::cout << "\n ============== ALL TESTS PASSED ============== "
              << std::endl
              << std::endl;

    // will be compilation error because of template guard
    // int foo = 5;
    // easyfind(foo, 'e');

  } catch (const std::exception& e) {
    std::cout << "FAIL: " << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cout << "FAIL: unknown exception" << std::endl;
    return 1;
  }

  return 0;
}