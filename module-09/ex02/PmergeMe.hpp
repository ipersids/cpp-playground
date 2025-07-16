#pragma once

#include <chrono>
#include <deque>
#include <iostream>
#include <vector>

std::vector<int> generateJacobsthalNumbers(int max_index);

static int counter = 0;

/// @brief Search for position for target
/// @tparam T container type
/// @param container container of type T
/// @param target integer to insert
/// @param left left bound
/// @param right right bound
/// @return Index where target should be inserted
template <typename T>
int runBinarySearch(const T& container, typename T::value_type target, int left, int right) {
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (container[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
    counter += 1;
  }
  return left;
}

template <typename T>
T runFordJohnsonAlgorithm(T& container) {
  if (container.size() <= 1) {
    return container;
  }

  T largest, pending, odd;

  auto end = container.end();
  auto start = container.begin();
  for (; start + 1 < end; start += 2) {
    if (*start < *(start + 1)) {
      pending.push_back(*start);
      largest.push_back(*(start + 1));
    } else {
      pending.push_back(*(start + 1));
      largest.push_back(*start);
    }
    counter += 1;
  }

  if (start != end) {
    odd.push_back(*start);
  }

  T sorted_largest = runFordJohnsonAlgorithm(largest);

  T main_chain = {sorted_largest[0]};
  if (pending.size() > 1) {
    main_chain.insert(main_chain.begin(), pending[0]);
    pending.erase(pending.begin());
  }

  for (size_t i = 1; i < sorted_largest.size(); ++i) {
    main_chain.push_back(sorted_largest[i]);
  }

  std::vector<int> jacobsthal = generateJacobsthalNumbers(pending.size());
  int inserted_count = 0;

  for (int it: jacobsthal) {
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
    int pos = runBinarySearch(main_chain, element, 0, static_cast<int>(main_chain.size()));
    main_chain.insert(main_chain.begin() + pos, element);
    inserted_count += 1;
  }

  if (!odd.empty()) {
    int pos = runBinarySearch(main_chain, odd[0], 0, static_cast<int>(main_chain.size()));
    main_chain.insert(main_chain.begin() + pos, odd[0]);
  }

  return main_chain;
}
