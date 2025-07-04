#include <cassert>
#include <iostream>
#include <limits>
#include <ranges>

#include "Span.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

#define MAX_SPAN_SIZE 15

int main() {
  Span sp = Span(7);

  std::cout << BLUE "\n =========== TEST 1: EMPTY SPAN (THROW) =========== \n"
            << RESET << std::endl;

  try {
    sp.shortestSpan();
    assert(false && "Test error: shortest span should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  try {
    sp.longestSpan();
    assert(false && "Test error: longest span should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  std::cout << BLUE "\n ====== TEST 2: ONLY ELEMENT IN SPAN (THROW) ====== \n"
            << RESET << std::endl;

  sp.addNumber(6);

  try {
    sp.shortestSpan();
    assert(false && "Test error: shortest span should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  try {
    sp.longestSpan();
    assert(false && "Test error: longest span should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  std::cout << BLUE "\n ========= TEST 3: SIMPLE POSITIVE NUMBERS ======== \n"
            << RESET << std::endl;

  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);

  unsigned int shortest_span = sp.shortestSpan();
  unsigned int longest_span = sp.longestSpan();

  assert(shortest_span == 2 && "Error: shortest span fails");
  assert(longest_span == 14 && "Error: longest span fails");

  std::cout << "Shortest span = " << shortest_span << std::endl;
  std::cout << "Longest span = " << longest_span << std::endl;

  std::cout << BLUE "\n ========= TEST 4.1: ADD INT_MIN / INT_MAX ======== \n"
            << RESET << std::endl;

  sp.addNumber(std::numeric_limits<int>::max());
  sp.addNumber(std::numeric_limits<int>::min());

  shortest_span = sp.shortestSpan();
  longest_span = sp.longestSpan();

  assert(shortest_span == 2 && "Error: shortest span fails");
  unsigned int teat_case = std::numeric_limits<unsigned int>::max();
  assert(longest_span == teat_case && "Error: longest span fails");

  std::cout << "Shortest span = " << shortest_span << std::endl;
  std::cout << "Longest span = " << longest_span << std::endl;

  std::cout << BLUE "\n === TEST 4.2: SPAN WITH ONLY INT_MIN / INT_MAX === \n"
            << RESET << std::endl;

  Span stresss_test = Span(2);

  stresss_test.addNumber(std::numeric_limits<int>::min());
  stresss_test.addNumber(std::numeric_limits<int>::max());

  shortest_span = stresss_test.shortestSpan();
  longest_span = stresss_test.longestSpan();

  assert(shortest_span == teat_case && "Error: shortest span fails");
  assert(longest_span == teat_case && "Error: longest span fails");

  std::cout << "Shortest span = " << shortest_span << std::endl;
  std::cout << "Longest span = " << longest_span << std::endl;

  std::cout << BLUE "\n ========== TEST 5: OUT OF RANGE (THROW) ========== \n"
            << RESET << std::endl;

  try {
    sp.addNumber(23);
    assert(false && "Test error: addNumber should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  try {
    stresss_test.addNumber(23);
    assert(false && "Test error: addNumber should fail!");
  } catch (const std::exception& e) {
    std::cout << GREEN "Expected fail: \n" << RESET << e.what() << std::endl;
  }

  std::cout << BLUE "\n ======== TEST 6: FILL SPAN WITH ITERATORS ======== \n"
            << RESET << std::endl;

  Span iter_sp(MAX_SPAN_SIZE);

#ifdef __cpp_concepts
  auto rang_arr = std::views::iota(0, MAX_SPAN_SIZE);
#else
  std::vector<int> rang_arr;
  rang_arr.reserve(MAX_SPAN_SIZE);
  for (int i = 0; i < MAX_SPAN_SIZE; ++i) {
    rang_arr.push_back(i);
  }
#endif

  std::cout << "Display first 15 elements in range of " << MAX_SPAN_SIZE << ":"
            << std::endl;
  int counter = 0;
  for (int i : rang_arr) {
    std::cout << i << " ";
    if (++counter == 15) {
      break;
    }
  }

  std::cout << "\n\nFiil Span using range from 0 to " << MAX_SPAN_SIZE << ":"
            << std::endl;
  iter_sp.addNumber(rang_arr.begin(), rang_arr.end());

  shortest_span = iter_sp.shortestSpan();
  longest_span = iter_sp.longestSpan();

  assert(shortest_span == 1 && "Error: shortest span fails");
  assert(longest_span == MAX_SPAN_SIZE - 1 && "Error: longest span fails");

  std::cout << " - Shortest span = " << shortest_span << std::endl;
  std::cout << " - Longest span = " << longest_span << std::endl;

  // iter_sp.addNumber(0, 2); // will be a compilation error

  std::cout << BLUE "\n                ALL TESTS PASSED                   \n"
            << RESET << std::endl;
  return 0;
}