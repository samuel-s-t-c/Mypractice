#include <iostream>
#include <algorithm>
#include <iterator>
#include <memory>
#include "MyString.h"
#include "StrVec.h"

//============================================================
//
//     constructors
//
//============================================================
StrVec::StrVec(const StrVec &obj)
{
  #ifndef NDEBUG
  std::cout << "vec copy constructor\n";
  #endif
  auto newdata = alloc_n_copy(obj.begin(), obj.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::StrVec(const std::initializer_list<String> &lst)
{
  #ifndef NDEBUG
  std::cout << "vec initializer constructor\n";
  #endif
  auto newdata = alloc_n_copy(lst.begin(), lst.end());
  elements = newdata.first;
  cap = first_free = newdata.second;
}

StrVec::StrVec(StrVec &&rhs) noexcept
  :elements(rhs.elements), first_free(rhs.first_free), cap(rhs.cap)
{
  rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

//============================================================
//
//     destrcutor
//
//============================================================
StrVec::~StrVec()
{
  free();
}

//============================================================
//
//     operators: copy-assignment, move-assignment,
//
//============================================================
// copy-assignment / move-assignment operators
//============================================================
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
//============================================================
// equality/inequality
//============================================================
bool operator==(const StrVec &lhs, const StrVec &rhs)
{
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
  return !(lhs == rhs);
}

//============================================================
//
//               other members
//
//============================================================
//               static members
//============================================================
std::allocator<String> StrVec::alloc;

//============================================================
//               function members
//============================================================

void StrVec::push_back(const String &s)
{
  #ifndef NDEBUG
  std::cout << "vec push_back copy\n";
  #endif
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::push_back(String &&s)
{
  #ifndef NDEBUG
  std::cout << "vec push_back move\n";
  #endif
  chk_n_alloc();
  alloc.construct(first_free++, std::move(s));
}

//============================================================
//             utility functions
//============================================================
std::pair<String*, String*>
StrVec::alloc_n_copy(const String *b, const String *e)
{
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
  #ifndef NDEBUG
  std::cout << "vec free" << std::endl;
  #endif
  if (elements) {
    // for (auto p = first_free; p != elements; /* empty */) {
    //   alloc.destroy(--p);
    // }
    std::for_each(elements, first_free, [this](String &p){alloc.destroy(&p);});
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
  #ifndef NDEBUG
  std::cout << "vec reallocate\n";
  #endif
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);
  auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
}
