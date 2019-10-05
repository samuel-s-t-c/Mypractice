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
//
//  ConstStrBlobPtr operators
//
//============================================================
