////////////////////////////////////////////////////////////////////////////////
// description : to print out the map
// improvements: using private members with class(not a structure)
//               custom error handling for functions
// comments    :
////////////////////////////////////////////////////////////////////////////////
#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "Point.hpp"

struct Map {
  Map(int w, int h) : _width_(w), _height_(h), _player_(w/2,h/2) {
    if (w < 1 || h < 1)
      std::cerr << "Invalid Size" << std::endl;
  }
  void left(void) {
    if (_player_._x_ > 0)
      _player_.left();
  }
  void right(void) {
    if (_player_._x_ < _width_-1)
      _player_.right();
  }
  void up(void) {
    if (_player_._y_ > 0)
      _player_.up();
  }
  void down(void) {
    if (_player_._y_ < _height_-1)
      _player_.down();
  }
  // variables
  int _width_, _height_;
  Point _player_;
};

std::ostream& operator<<(std::ostream& s, Map const& m) {
  std::cout << ' ';
  for (int j = 0; j < m._width_*2+2; ++j) {
    std::cout << char(220);
  }
  std::cout << std::endl;
  for (int i = 0; i < m._height_; ++i) {
    std::cout << ' ' << char(219);
    for (int j = 0; j < m._width_; ++j) {
      if (i == m._player_._y_ && j == m._player_._x_)
        std::cout << char(178) << char(178);
      else
        std::cout << "  ";
    }
    std::cout << char(219) << std::endl;
  }
  std::cout << ' ';
  for (int j = 0; j < m._width_*2+2; ++j) {
    std::cout << char(223);
  }
  return s;
}

#endif