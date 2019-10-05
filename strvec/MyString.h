#ifndef MYSTRINGH
#define MYSTRINGH

#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>

class String {
  friend std::ostream &operator<<(std::ostream &os, const String &rhs);
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);
  friend bool operator<(const String &, const String &);
  friend bool operator>(const String &, const String &);
  friend bool operator<=(const String &, const String &);
  friend bool operator>=(const String &, const String &);
public:
  //constructor
  String() : begin_(nullptr), end_(nullptr), cap(nullptr) { }
  String(const String &rhs);
  String(String &&rhs) noexcept;
  String(const char[]);
  //destructor
  ~String(){free();}
  //operator
  String &operator=(const String &rhs);
  String &operator=(String &&rhs) noexcept;
  //member funcions
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

#endif
