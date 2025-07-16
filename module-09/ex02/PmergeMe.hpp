#pragma once

#include <chrono>
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> generateJacobsthalNumbers(int max_index);

template <typename T>
auto runFordJohnsonAlgorithm(T& container) -> decltype(std::begin(container),
                                                       std::end(container),
                                                       *std::begin(container)) {
  if (container.size() <= 1) {
    return container;
  }

  T smallest, largest, odd;

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

  /// >>> @test
  for (auto it : smallest) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  for (auto it : largest) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  for (auto it : odd) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  /// <<< end @test

  T sorted = largest;
  if (largest.size() > 1) sorted = runFordJohnsonAlgorithm(largest);
}
