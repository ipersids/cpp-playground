/**
 * @file Point.hpp
 * @author Julia Persidskaia
 * @date 2025-04-03
 */

#ifndef POINT_EX03_HPP_
#define POINT_EX03_HPP_

#include <iostream>

#include "Fixed.hpp"

class Point {
 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& other);
  Point& operator=(const Point& other) = delete;
  ~Point();

  float getX(void) const;
  float getY(void) const;
  static float getTriangleArea(Point const& a, Point const& b, Point const& c);

 private:
  const Fixed _x;
  const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // POINT_EX03_HPP_