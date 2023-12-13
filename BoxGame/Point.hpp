////////////////////////////////////////////////////////////////////////////////
// description : to use an object which has x, y positions
// improvements: using private members with class(not a structure)
//               custom error handling for functions
// comments    :
////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

struct Point {
  Point(int x, int y) : _x_(x), _y_(y) {}
  Point& operator=(const Point& p) {
    _x_ = p._x_;
    _y_ = p._y_;
    return *this;
  }
  void left(void) { _x_--; }
  void right(void) { _x_++; }
  void up(void) { _y_--; }
  void down(void) { _y_++; }
  // variables
  int _x_, _y_;
};

#endif