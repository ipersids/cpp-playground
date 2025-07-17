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
int runBinarySearch(const T& container, typename T::value_type target, int left,
                    int right) {
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
    counter += 1;
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
