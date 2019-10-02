#ifndef MYSTRINGH
#define MYSTRINGH

#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>

class string {
  friend std::ostream &operator<<(std::ostream &os, const string &rhs);
public:
  string() : begin_(nullptr), end_(nullptr), cap(nullptr) { }
  string(const string &rhs);
  string(const char[]);
  ~string(){free();}
  string &operator=(const string &rhs);
  std::size_t size() const {return end_ - begin_;}
  char *begin() const {return begin_;}
  char *end() const {return end_;}
private:
  static std::allocator<char> alloc;
  char *begin_;
  char *end_;
  char *cap;
  std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);
  void free();
};
std::allocator<char> string::alloc;

void string::free()
{
  if (begin_) {
    for (auto i = end_; i != begin_; )
      alloc.destroy(--i);
    alloc.deallocate(begin_, cap-begin_);
  }
}

std::pair<char*, char*> string::alloc_n_copy(const char *b, const char *e)
{
  auto data = alloc.allocate(e-b);
  return {data, std::uninitialized_copy(b, e, data)};
}

string::string(const string &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  begin_ = newdata.first;
  cap = end_ = newdata.second;
}

string::string(const char cstr[] )
{
  auto end = cstr - 1;
  while (*++end != '\0')
    continue;
  auto newdata = alloc_n_copy(cstr, end);
  begin_ = newdata.first;
  cap = end_ = newdata.second;
}

std::ostream &operator<<(std::ostream &os, const string &rhs)
{
  for (auto i = rhs.begin(); i != rhs.end(); ++i) {
    os << *i;
  }
  return os;
}

string &string::operator=(const string &rhs)
{
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  begin_ = newdata.first;
  cap = end_ = newdata.second;
  return *this;
}

#endif
