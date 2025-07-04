#pragma once

#include <deque>
#include <iterator>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T> {
 public:
  ~MutantStack() = default;
  // inherit constractors from base class
  using std::stack<T>::stack;
  // add non-const and const iterator types
  using iterator = typename Container::iterator;
  using const_iterator = typename Container::const_iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }
};
