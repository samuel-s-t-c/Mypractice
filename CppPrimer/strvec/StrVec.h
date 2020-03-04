#ifndef STRVECH
#define STRVECH

#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "MyString.h"

class StrVec {
  friend bool operator==(const StrVec &lhs, const StrVec &rhs);
  friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
  friend bool operator<(const StrVec &lhs, const StrVec &rhs);
  friend bool operator>(const StrVec &lhs, const StrVec &rhs);
  friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
  friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
  //**********constructors**********
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
  StrVec(const StrVec &obj);
  StrVec(StrVec &&obj) noexcept;
  StrVec(const std::initializer_list<String> &lst);
  //**********destrcutor**********
  ~StrVec();
  //**********overloaded operators**********
  StrVec &operator=(const StrVec &rhs);
  StrVec &operator=(const std::initializer_list<String> &rhs);
  StrVec &operator=(StrVec &&rhs) noexcept;
  String &operator[](std::size_t n);
  const String &operator[](std::size_t n) const;
  //**********other methods**********
  template <typename... Args> void emplace_back(Args&&... args);
  void push_back(const String &s);
  void push_back(String &&s);
  std::size_t size() const {return first_free - elements;};
  std::size_t capacity() const {return cap - elements;};
  String *begin() const {return elements;};
  String *end() const {return first_free;};
private:
  static std::allocator<String> alloc;
  String *elements;
  String *first_free;
  String *cap;
  //utility functions
  std::pair<String*, String*> alloc_n_copy(const String *b, const String *e);
  void free();
  void chk_n_alloc();
  void reallocate();
};

// declarations of friends
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);
bool operator<=(const StrVec &lhs, const StrVec &rhs);
bool operator>=(const StrVec &lhs, const StrVec &rhs);

template <typename... Args> inline
void StrVec::emplace_back(Args&&... args)
{
  chk_n_alloc();
  alloc.construct(first_free++, std::forward<Args>(args)...);
}
#endif
