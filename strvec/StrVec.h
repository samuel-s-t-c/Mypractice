#ifndef STRVECH
#define STRVECH 
#include <memory>
// #include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "MyString.h"

class StrVec {

public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec &obj);
  StrVec(StrVec &&obj) noexcept;
  StrVec(const std::initializer_list<string>& );
  ~StrVec();
  StrVec &operator=(const StrVec &rhs);
  StrVec &operator=(StrVec &&rhs) noexcept;
  void push_back(const string &s);
  std::size_t size() const {return first_free - elements;};
  std::size_t capacity() const {return cap - elements;};
  string *begin() const {return elements;};
  string *end() const {return first_free;};
private:
  static std::allocator<string> alloc;
  string *elements;
  string *first_free;
  string *cap;
  //utility functions
  std::pair<string*, string*> alloc_n_copy(const string *b, const string *e);
  void free();
  void chk_n_alloc();
  void reallocate();
};

std::allocator<string> StrVec::alloc;

StrVec::StrVec(const StrVec &obj)
{
  auto newdata = alloc_n_copy(obj.begin(), obj.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::StrVec(const std::initializer_list<string> &lst)
{
  auto newdata = alloc_n_copy(lst.begin(), lst.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept
  :elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
  rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

StrVec::~StrVec()
{
  free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

void StrVec::push_back(const string &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  std::cout << "free" << std::endl;
  if (elements) {
    // for (auto p = first_free; p != elements; /* empty */) {
    //   alloc.destroy(--p);
    // }
    std::for_each(elements, first_free, [this](string p){alloc.destroy(&p);});
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::chk_n_alloc()
{
  if (size() == capacity())
    reallocate();
}

void StrVec::reallocate()
{
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);
  auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
}

#endif
