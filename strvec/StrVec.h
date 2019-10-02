#ifndef STRVECH
#define STRVECH

#include <memory>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

class StrVec {

public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec &obj);
  StrVec(const std::initializer_list<std::string>& );
  ~StrVec();
  StrVec &operator=(StrVec &rhs);
  void push_back(const std::string &s);
  std::size_t size() const {return first_free - elements;};
  std::size_t capacity() const {return cap - elements;};
  std::string *begin() const {return elements;};
  std::string *end() const {return first_free;};
private:
  static std::allocator<std::string> alloc;
  std::string *elements;
  std::string *first_free;
  std::string *cap;
  //utility functions
  std::pair<std::string*, std::string*> alloc_n_copy(const std::string *b, const std::string *e);
  void free();
  void chk_n_alloc();
  void reallocate();
};

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &obj)
{
  auto newdata = alloc_n_copy(obj.begin(), obj.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &lst)
{
  auto newdata = alloc_n_copy(lst.begin(), lst.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::~StrVec()
{
  free();
}

StrVec &StrVec::operator=(StrVec &rhs)
{
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::push_back(const std::string &s)
{
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
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
    std::for_each(elements, first_free, [this](std::string p){alloc.destroy(&p);});
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
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

#endif
