#include "Sales_data.h"
#include <iostream>

// operator

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
  return lhs.bookNo == rhs.bookNo &&
         lhs.units_sold == rhs.units_sold &&
         lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
  return !(lhs == rhs);
}

Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
  bookNo = rhs.bookNo;
  units_sold = rhs.units_sold;
  revenue = rhs.revenue;
  return *this;
}

Sales_data &Sales_data::operator=(Sales_data &&rhs)
{
  if (this != &rhs) {
    bookNo = std::move(rhs.bookNo);
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    rhs.bookNo = "";
  }
  return *this;
}

std::istream &operator>>(std::istream &is,  Sales_data &item)
{
  Sales_data temp = item;
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  if (is)
    item.revenue =  price * item.units_sold;
  else {
    item = std::move(temp);
  }
  return is;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item)
{
  os << item.bookNo << ' '
     << item.units_sold << ' '
     << item.revenue << ' '
     << item.avg_price();
  return os;
}

Sales_data operator+(Sales_data lhs, const Sales_data &rhs)
{
  return lhs += rhs;
}

// public member functions
std::istream &read(std::istream &is,  Sales_data &item)
{
  return is >> item;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
  return os << item;
}

Sales_data add(const Sales_data&lhs, const Sales_data&rhs)
{
  return lhs + rhs;
}
