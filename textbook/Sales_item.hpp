////////////////////////////////////////////////////////////////////////////////
// improvements: using private members
//               custom error handling for functions
//               turn into h file (not hpp)
// comments    : operator <<, >> - tried inside of the class but didn't work,
//                implemented it outside of the class later, and it worked!!
//               codeguard(ifndef, define, endif) is not from the book,
//                it's from the course CS170
////////////////////////////////////////////////////////////////////////////////
#ifndef SALES_ITEM_HPP
#define SALES_ITEM_HPP

#include <iostream>
#include <string>

class Sales_item {
  public:
    std::string isbn(void) { return _isbn_; }
    Sales_item& operator=(Sales_item const& i) {
      _isbn_ = i._isbn_;
      _copy_ = i._copy_;
      _total_ = i._total_;
      _price_ = i._price_;
      return *this;
    }
    Sales_item operator+(Sales_item const& a) {
    Sales_item i;
    i._isbn_ = _isbn_;
    i._copy_ = a._copy_ + _copy_;
    i._total_ = a._total_ + _total_;
    i._price_ = i._total_ / i._copy_;
    return i;
    // add error handling? with an error message?
  }
    Sales_item& operator+=(Sales_item const& i) {
      _copy_ += i._copy_;
      _total_ += i._total_;
      _price_ = _total_ / _copy_ ;
      return *this;
    }
  // private:
    std::string _isbn_;
    int _copy_;         // number of copies sold
    double _total_;     // total revenue
    double _price_;     // average sales price
};

std::ostream& operator<<(std::ostream& s, Sales_item const& i) {
  s << i._isbn_ << ' ' << i._copy_ << ' ' << i._total_ << ' ' << i._price_;
  return s;
}
std::istream& operator>>(std::istream& s, Sales_item& i) {
  s >> i._isbn_ >> i._copy_ >> i._price_;
  i._total_ = i._copy_*i._price_;
  return s;
}

#endif