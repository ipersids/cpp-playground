#include <iostream>
#include <algorithm>
#include "PmergeMe.hpp"

#ifndef COLORS
#define COLORS
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS


void testFordJohnson() {
    std::vector<std::vector<int>> test_cases = {
        {},
        {42},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {3, 1, 4, 1, 5, 9, 2},
        {10, 5, 2, 8, 1, 9, 3, 7, 10, 21, 18, 17, 19}
    };

    for (const auto& test : test_cases) {
        counter = 0;
        auto input = test;
        auto expected = test;
        std::sort(expected.begin(), expected.end());

        auto result = runFordJohnsonAlgorithm(input);

        bool valid = std::is_sorted(result.begin(), result.end()) &&
                     std::is_permutation(result.begin(), result.end(), expected.begin());

        std::cout << (valid ? "✅" : "❌") << " Input: ";
        for (int val : test) std::cout << val << " ";
        std::cout << "\n   Output: ";
        for (int val : result) std::cout << val << " ";
        std::cout << "\n   Comparisons: " << counter << "\n\n";
    }
}

int main(int argc, char** argv) {
  (void)argc;
  (void)(argv);
  // if (argc < 2) {
  //   std::cerr << MAGENTA "Usage: " << RESET "./PmergeMe <a positive integer sequence>" << std::endl;
  //   return 1;
  // }
  // std::vector<int> v = {5, 2, 8, 1, 9, 3, 7, 10, 21, 18, 17, 19};
  // for (auto it : v) std::cout << it << " ";
  // std::cout << std::endl;

  // counter = 0;
  // v = runFordJohnsonAlgorithm(v);
  // for (auto it : v) std::cout << it << " ";
  // std::cout << "counter " << counter << std::endl;

  // counter = 0;
  // std::deque<int> d = {5, 2, 8, 1, 9, 3, 7, 10, 21, 18, 17, 19};
  // d = runFordJohnsonAlgorithm(d);
  // for (auto it : d) std::cout << it << " ";
  // std::cout << "counter " << counter << std::endl;
  testFordJohnson();
  return 0;
}
