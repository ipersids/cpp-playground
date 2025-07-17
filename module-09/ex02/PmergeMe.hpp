#pragma once

#include <algorithm>
#include <chrono>
#include <deque>
#include <exception>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#ifndef COLORS
#define RED "\033[31m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"
#endif  // COLORS

class PmergeMe {
 public:
  PmergeMe() = delete;
  PmergeMe& operator=(const PmergeMe& other) = delete;
  PmergeMe(const PmergeMe& other) = delete;
  ~PmergeMe();

  PmergeMe(int amoutn, char** numbers);

 private:
  std::vector<int> _vec;
  std::deque<int> _deque;
  std::vector<int> _input;
  double _duration_vec;
  double _duration_deque;

  /// Helpers
  void validateInput(int amount, char** numbers);
  bool isIntenger(const std::string& literal);
  std::vector<int> generateJacobsthalNumbers(int max_index);
  void validateResultAndPrint();

  /// Templates
  template <typename T>
  int runBinarySearch(const T& container, typename T::value_type target,
                      int left, int right);
  template <typename T>
  T runFordJohnsonAlgorithm(T& container);
};

/// @brief Search for position for target
/// @tparam T container type
/// @param container container of type T
/// @param target integer to insert
/// @param left left bound
/// @param right right bound
/// @return Index where target should be inserted
template <typename T>
int PmergeMe::runBinarySearch(const T& container, typename T::value_type target,
                              int left, int right) {
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (container[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

template <typename T>
T PmergeMe::runFordJohnsonAlgorithm(T& container) {
  if (container.size() <= 1) {
    return container;
  }

  T largest, smallest, odd;

  auto end = container.end();
  auto start = container.begin();
  for (; start + 1 < end; start += 2) {
    if (*start < *(start + 1)) {
      smallest.push_back(*start);
      largest.push_back(*(start + 1));
    } else {
      smallest.push_back(*(start + 1));
      largest.push_back(*start);
    }
  }

  if (start != end) {
    odd.push_back(*start);
  }

  T sorted_largest = runFordJohnsonAlgorithm(largest);

  std::vector<bool> visited(sorted_largest.size(), false);
  T pending;
  for (int val : sorted_largest) {
    for (size_t i = 0; i < sorted_largest.size(); ++i) {
      if (val == largest[i] && !visited[i]) {
        pending.push_back(smallest[i]);
        visited[i] = true;
      }
    }
  }

  T main_chain;
  if (!pending.empty()) {
    main_chain.insert(main_chain.begin(), pending[0]);
    pending.erase(pending.begin());
  }

  for (const auto& elem : sorted_largest) {
    main_chain.push_back(elem);
  }

  std::vector<int> jacobsthal = generateJacobsthalNumbers(pending.size());
  int inserted_count = 0;

  for (int it : jacobsthal) {
    if (it > static_cast<int>(pending.size())) {
      break;
    }
    int lim = std::min(it, static_cast<int>(pending.size()));
    for (int k = lim; k >= inserted_count + 1; --k) {
      int element = pending[k - 1];
      int right_pos = std::min(static_cast<int>(main_chain.size()), k + lim);
      int pos = runBinarySearch(main_chain, element, 0, right_pos);
      main_chain.insert(main_chain.begin() + pos, element);
    }
    inserted_count = lim;
  }

  while (inserted_count < static_cast<int>(pending.size())) {
    int element = pending[inserted_count];
    int pos = runBinarySearch(main_chain, element, 0,
                              static_cast<int>(main_chain.size()));
    main_chain.insert(main_chain.begin() + pos, element);
    inserted_count += 1;
  }

  if (!odd.empty()) {
    int pos = runBinarySearch(main_chain, odd[0], 0,
                              static_cast<int>(main_chain.size()));
    main_chain.insert(main_chain.begin() + pos, odd[0]);
  }

  return main_chain;
}
