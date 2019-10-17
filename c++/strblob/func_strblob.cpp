#include "StrBlob.h"

//============================================================
//
//  StrBlob operators
//
//============================================================
bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
  return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
  return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
  return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(rhs < lhs);
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
  return !(lhs < rhs);
}

//============================================================
//
//  StrBlobPtr operators
//
//============================================================
//  StrBlobPtr: equality/relational operators
//============================================================
StrBlobPtr &StrBlobPtr::operator=(const StrBlobPtr &rhs)
{
  wptr = rhs.wptr;
  index = rhs.index;
  return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return lhs.wptr.lock() == rhs.wptr.lock() &&
    lhs.index == rhs.index;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return !(lhs == rhs);
}

//============================================================
//  StrBlobPtr: arithmetic operators
//============================================================
StrBlobPtr StrBlobPtr::operator+(std::size_t n)
{
  StrBlobPtr ret = *this;
  return ret += n;
}

StrBlobPtr &StrBlobPtr::operator+=(std::size_t n)
{
  check(index += n, "access past end of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator-(std::size_t n)
{
  StrBlobPtr ret = *this;
  return ret -= n;
}

StrBlobPtr &StrBlobPtr::operator-=(std::size_t n)
{
  check(index -= n, "access past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr &StrBlobPtr::operator++()
{
  check(index, "increment past end of StrBlobPtr");
  ++index;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
  check(--index, "increment past end of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
  StrBlobPtr temp = *this;
  ++*this;
  return temp;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
  StrBlobPtr temp = *this;
  --*this;
  return temp;
}

std::size_t operator-(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
  return lhs.index - rhs.index;
}

//============================================================
//
//  ConstStrBlobPtr operators
//
//============================================================
