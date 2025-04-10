/**
 * @file iter.hpp
 * @author Julia Persidskaia (julia.persidskaia@gmail.com)
 * @date 2025-04-10
*/

#ifndef ITER_EX01_HPP_
#define ITER_EX01_HPP_

#include <iostream>

template <typename T>
void iter(T* arr, int len, void (*func)(T&)) {
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

// helper functions for tests
template <typename T>
void print_test(T& val) {
	std::cout << val << " " << std::flush;
}

template <typename T>
void add_const_test(T& val) {
	val += 2;
}

#endif // ITER_EX01_HPP_