
#include <iostream>
#include "MyString.h"

//============================================================
//
//              private member
//
//============================================================
std::allocator<char> String::alloc;

void String::free()
{
  #ifndef NDEBUG
  std::cout << "String destroy deallocate\n";
  #endif
  if (begin_) {
    for (auto i = end_; i != begin_; )
      alloc.destroy(--i);
    alloc.deallocate(begin_, cap-begin_);
  }
}

void String::chk_n_alloc()
{
  if (end_ == cap)
    realloc_str();
}

void String::realloc_str()
{
  #ifndef NDEBUG
  std::cout << "String reallocate deallocate\n";
  #endif
  auto newCapability = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newCapability);
  auto end = std::uninitialized_copy(std::move(begin_), std::move(end_), first);
  alloc.deallocate(begin_, size());
  begin_ = first;
  end_ = end;
  cap = begin_ + newCapability;
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
  auto data = alloc.allocate(e-b);
  return {data, std::uninitialized_copy(b, e, data)};
}

//============================================================
//
//                 constructor
//
//============================================================

String::String(std::size_t n, char c)
  : begin_(alloc.allocate(n)), end_(begin_ + n), cap(begin_ + n)
{
  #ifndef NDEBUG
  std::cout << "String default/(num, char) constructor\n";
  #endif
  if ( c != '\0')
    for (auto i = begin_; i != end_ ; ++i)
      alloc.construct(i, c);
}

String::String(const String &rhs)
{
  #ifndef NDEBUG
  std::cout << "String copy constructor\n";
  #endif
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  begin_ = newdata.first;
  cap = end_ = newdata.second;
}

String::String(String &&rhs) noexcept
  :begin_(rhs.begin_), end_(rhs.end_), cap(rhs.cap)
{
  #ifndef NDEBUG
  std::cout << "String move constructor\n";
  #endif
  rhs.begin_ = rhs.end_ = rhs.cap = nullptr;
}

String::String(const char cstr[] )
{
  #ifndef NDEBUG
  std::cout << "Stinrg c-String constructor\n";
  #endif
  auto end = cstr - 1;
  while (*++end != '\0')
    continue;
  auto newdata = alloc_n_copy(cstr, end);
  begin_ = newdata.first;
  cap = end_ = newdata.second;
}

//============================================================
//
//                    operator
//
//============================================================
//============================================================
//                   io operator
//============================================================
std::ostream &operator<<(std::ostream &os, const String &rhs)
{
  for (auto i = rhs.begin(); i != rhs.end(); ++i) {
    os << *i;
  }
  return os;
}

std::istream &operator>>(std::istream &is, String &rhs)
{
  // char c = '\0';
  // while (std::cin.get(c) && c != ' ' && c != '\n')
  //   {
  //     rhs.chk_n_alloc();
  //     rhs.push_back(c);
  //     std::cout << "out\n";
  //   }
  return is;
}

//============================================================
//                assignment operator
//============================================================
String &String::operator=(const String &rhs)
{
#ifndef NDEBUG
  std::cout << "overloaded operator =\n";
  #endif
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  begin_ = newdata.first;
  cap = end_ = newdata.second;
  return *this;
}

String &String::operator=(String &&rhs) noexcept
{
  if (this != &rhs) {
    begin_ = rhs.begin_;
    end_ = rhs.end_;
    cap = rhs.cap;
    rhs.begin_ = rhs.end_ = rhs.cap = nullptr;
  }
  return *this;
}

//============================================================
//                   equality/inequality operator
//============================================================
bool operator==(const String &lhs, const String &rhs)
{
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs)
{
  return !(lhs == rhs);
}

//============================================================
//            relational operator
//============================================================
bool operator<(const String &lhs, const String &rhs)
{
  if (lhs.size() > rhs.size())
    return rhs <  lhs;
  else {
    for (auto l = lhs.begin_, r = rhs.begin_;
         l != lhs.end_; ++l, ++r) {
      std::cout << (int)*l << " " << (int)*r << std::endl;
      if (*l > *r)
        return false;
      else if (*l < *r)
        return true;
    }
    if (lhs.size() == rhs.size())
      return false;
    return true;
  }
}

bool operator>(const String &lhs, const String &rhs)
{
  return rhs < lhs;
}
bool operator<=(const String &lhs, const String &rhs)
{
  return !(rhs < lhs);
}
bool operator>=(const String &lhs, const String &rhs)
{
  return !(lhs < rhs);
}

//============================================================
//            subscript operator
//============================================================
char &String::operator[](std::size_t n)
{
  return begin_[n];
}
const char &String::operator[](std::size_t n) const
{
  return begin_[n];
}

//============================================================
//        other methods
//============================================================
