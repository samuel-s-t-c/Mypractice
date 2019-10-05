#include "MyString.h"

//private member
std::allocator<char> String::alloc;

void String::free()
{
  #ifndef NDEBUG
  std::cout << "StringFree\n";
  #endif
  if (begin_) {
    for (auto i = end_; i != begin_; )
      alloc.destroy(--i);
    alloc.deallocate(begin_, cap-begin_);
  }
}

std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
  auto data = alloc.allocate(e-b);
  return {data, std::uninitialized_copy(b, e, data)};
}

//constructor
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
  std::cout << "stinrg c-String constructor\n";
  #endif
  auto end = cstr - 1;
  while (*++end != '\0')
    continue;
  auto newdata = alloc_n_copy(cstr, end);
  begin_ = newdata.first;
  cap = end_ = newdata.second;
}

//operator
std::ostream &operator<<(std::ostream &os, const String &rhs)
{
  for (auto i = rhs.begin(); i != rhs.end(); ++i) {
    os << *i;
  }
  return os;
}

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

bool operator==(const String &lhs, const String &rhs)
{
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs)
{
  return !(lhs == rhs);
}
