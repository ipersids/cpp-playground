#include "PmergeMe.hpp"

PmergeMe::~PmergeMe() {
  _input.clear();
  _vec.clear();
  _deque.clear();
}

PmergeMe::PmergeMe(int amount, char** numbers) {
  typedef std::chrono::high_resolution_clock::time_point Time;
  validateInput(amount, numbers);

  Time start_vec = std::chrono::high_resolution_clock::now();
  std::copy(_input.begin(), _input.end(), std::back_inserter(_vec));
  _vec = runFordJohnsonAlgorithm(_vec);
  Time end_vec = std::chrono::high_resolution_clock::now();

  Time start_deque = std::chrono::high_resolution_clock::now();
  std::copy(_input.begin(), _input.end(), std::back_inserter(_deque));
  _deque = runFordJohnsonAlgorithm(_deque);
  Time end_deque = std::chrono::high_resolution_clock::now();

  _duration_vec =
      std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec)
          .count();
  _duration_deque = std::chrono::duration_cast<std::chrono::microseconds>(
                        end_deque - start_deque)
                        .count();

  validateResultAndPrint();
}

void PmergeMe::validateInput(int amount, char** numbers) {
  int num = 0;
  for (int i = 0; i < amount; ++i) {
    if (!isIntenger(numbers[i])) {
      std::cerr << RED << "Error: " << RESET << "Invalid integer input: '"
                << numbers[i] << "'" << std::endl;
      std::exit(1);
    }
    try {
      num = std::stoi(numbers[i]);
    } catch (std::exception const& e) {
      std::cerr << RED << "Error: " << RESET << e.what() << ": '" << numbers[i]
                << "'" << std::endl;
      std::exit(2);
    }
    if (num < 0) {
      std::cerr << RED << "Error: " << RESET
                << "Invalid integer input (negative): '" << numbers[i] << "'"
                << std::endl;
      std::exit(3);
    }
    _input.push_back(num);
  }
}

bool PmergeMe::isIntenger(const std::string& literal) {
  std::regex re(R"(^\s*[+-]?[1-9]\d*\s*|\s*0\s*$)");
  return std::regex_match(literal, re);
}

void PmergeMe::validateResultAndPrint() {
  std::vector expected = _input;
  std::sort(expected.begin(), expected.end());
  bool valid_vec =
      std::is_sorted(_vec.begin(), _vec.end()) &&
      std::is_permutation(_vec.begin(), _vec.end(), expected.begin());
  bool valid_deque =
      std::is_sorted(_deque.begin(), _deque.end()) &&
      std::is_permutation(_deque.begin(), _deque.end(), expected.begin());

  if (!valid_vec) {
    std::cerr << RED << "Fatal: " << RESET << "Invalid vector sorting result"
              << std::endl;
    std::exit(4);
  }

  if (!valid_deque) {
    std::cerr << RED << "Fatal: " << RESET << "Invalid vector sorting result"
              << std::endl;
    std::exit(4);
  }

  std::cout << MAGENTA << "Before: " << RESET;
  for (int it : _input) {
    std::cout << it << " ";
  }
  std::cout << MAGENTA << "\nAfter: " << RESET;
  for (int it : _vec) {
    std::cout << it << " ";
  }
  std::cout << "\nTime to process a range of " << _vec.size()
            << " elements with std::vector: " << _duration_vec << "µs";
  std::cout << "\nTime to process a range of " << _deque.size()
            << " elements with std::deque: " << _duration_deque << "µs"
            << std::endl;
}

/// @brief Sequence of integers that follow a specific recurrence relation.
/// In the Ford-Johnson algorithm, Jacobsthal numbers determine the optimal
/// insertion order for minimizing comparisons during the binary search phase:
/// J(n) = J(n-1) + 2·J(n-2)
/// @param n Maximum index needed
/// @return Array of Jacobsthal numbers up to n
std::vector<int> PmergeMe::generateJacobsthalNumbers(int n) {
  std::vector<int> jacobsthal_sequence = {0};
  if (n == 0) {
    return jacobsthal_sequence;
  }

  jacobsthal_sequence.push_back(1);

  int current = 1;   // J(n-1)
  int previous = 0;  // J(n-2)
  int next = current + (2 * previous);
  while (next <= n) {
    jacobsthal_sequence.push_back(next);
    previous = current;
    current = next;
    next = current + (2 * previous);
  }

  return jacobsthal_sequence;
}