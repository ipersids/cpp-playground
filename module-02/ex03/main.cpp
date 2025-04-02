#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

#ifndef COLORS
#define COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#endif  // COLORS

void test(Point const &a, Point const &b, Point const &c, Point const &p) {
  bool res = bsp(a, b, c, p);
  std::cout << BLUE << "Testing point (" << p.getX() << ", " << p.getY()
            << "): \nbsp = " << RESET;
  if (res)
    std::cout << GREEN << "TRUE" << RESET << std::endl;
  else
    std::cout << RED << "FALSE" << RESET << std::endl;
}

int main() {
  Point a(0, 0);
  Point b(5, 0);
  Point c(2.5, 5);
  Point inside(2.5, 2);
  Point edge(2.5, 0);
  Point vertex(0, 0);
  Point outside(5, 5);

  std::cout << BLUE << "\nTriangle vertices: A(0, 0), B(5, 0), C(2.5, 5)\n\n"
            << RESET;
  test(a, b, c, inside);
  test(a, b, c, edge);
  test(a, b, c, vertex);
  test(a, b, c, outside);

  return 0;
}