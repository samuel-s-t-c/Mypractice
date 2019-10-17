#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>
#include <functional>

class Sales_data {
  // friend declarations
  friend struct std::hash<Sales_data>;
  friend Sales_data operator+(Sales_data, const Sales_data&);
  friend std::ostream &operator<<(std::ostream&, const Sales_data&);
  friend std::istream &operator>>(std::istream&, Sales_data&);
  friend bool operator==(const Sales_data &, const Sales_data &);
  friend bool operator!=(const Sales_data &, const Sales_data &);
  friend std::ostream &print(std::ostream&, const Sales_data&);
  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend std::istream &read(std::istream&, Sales_data&);
public:
  // constructors
  Sales_data() : Sales_data("", 0, 0) { };
  Sales_data(const std::string &s, unsigned n, double p) :
    bookNo(s), units_sold(n), revenue(p*n) { }
  Sales_data(const Sales_data &rhs)
    : bookNo(rhs.bookNo), units_sold(rhs.units_sold), revenue(rhs.revenue) { }
  Sales_data(const std::string &s) : Sales_data(s, 0, 0) { }
  Sales_data(std::istream &is) : Sales_data() {is >> *this;};
  // destructor
  ~Sales_data() = default;
  // operator
  Sales_data &operator=(const Sales_data &rhs);
  Sales_data &operator=(Sales_data &&rhs);
  Sales_data &operator=(const std::string &rhs);
  Sales_data &operator+=(const Sales_data &rhs);
  //conversion operators
  explicit operator std::string() const {return bookNo;}
  explicit operator double() const {return revenue;}
  // member functions
  std::string isbn() const {return bookNo;}
  Sales_data& combine(const Sales_data &);
private:
  double avg_price() const
     {return units_sold ? revenue/units_sold : 0;};
  // data members
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
//declarations for nonmember part of the Sales_data interface
// Sales_data operator+(Sales_data, const Sales_data&);
Sales_data operator+(Sales_data, const Sales_data&);
std::ostream &operator<<(std::ostream&, const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data&);
bool operator==(const Sales_data &, const Sales_data &);
bool operator!=(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream&, const Sales_data&);
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

inline
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
  return *this += rhs;
}

inline
Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

inline
Sales_data &Sales_data::operator=(const std::string &rhs)
{
  bookNo = rhs;
  revenue = units_sold = 0;
  return *this;
}
namespace std {
  template <>
  struct hash<Sales_data> {
    typedef Sales_data argument_type;
    typedef size_t result_type;
    size_t operator()(const Sales_data &obj) const;
  };
}

#endif
