#include "PmergeMe.hpp"

/// @brief Sequence of integers that follow a specific recurrence relation.
/// In the Ford-Johnson algorithm, Jacobsthal numbers determine the optimal 
/// insertion order for minimizing comparisons during the binary search phase:
/// J(n) = J(n-1) + 2·J(n-2)
/// @param max_index Maximum index needed
/// @return Array of Jacobsthal numbers up to max_index
std::vector<int> generateJacobsthalNumbers(int max_index) {
  std::vector<int> jacobsthal_sequence = {1};

  int current = 1; // J(n-1)
  int previous = 1; // J(n-2)
  int next = current + (2 * previous);
  while (next <= max_index) {
    jacobsthal_sequence.push_back(next);
    previous = current;
    current = next;
    next = current + (2 * previous);
  }

  return jacobsthal_sequence;
}