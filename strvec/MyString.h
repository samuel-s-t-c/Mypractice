#ifndef MYSTRINGH
#define MYSTRINGH

#include <cstddef>
#include <memory>
#include <utility>
#include <iostream>

class String {
  friend std::ostream &operator<<(std::ostream &os, const String &rhs);
  friend std::istream &operator>>(std::istream &is, String &rhs);
  friend bool operator==(const String &, const String &);
  friend bool operator!=(const String &, const String &);
  friend bool operator<(const String &, const String &);
  friend bool operator>(const String &, const String &);
  friend bool operator<=(const String &, const String &);
  friend bool operator>=(const String &, const String &);
public:
  //constructor
  explicit String(std::size_t n = 15, char c = '\0');
  String(const String &rhs);
  String(String &&rhs) noexcept;
  String(const char[]);

  //destructor
  ~String(){free();}

  //operator
  String &operator=(const String &rhs);
  String &operator=(String &&rhs) noexcept;
  char &operator[](std::size_t n);
  const char &operator[](std::size_t n) const;
  //member funcions
  std::size_t size() const {return end_ - begin_;}
  std::size_t capacity() const {return cap - begin_;}
  char *begin() const {return begin_;}
  char *end() const {return end_;}
  void push_back(char c) {chk_n_alloc(); *end_++ = c;}
  bool compare(const String &l);
private:
  static std::allocator<char> alloc;
  char *begin_;
  char *end_;
  char *cap;
  std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);
  void free();
  void chk_n_alloc();
  void realloc_str();
};

// declarations
std::ostream &operator<<(std::ostream &os, const String &rhs);
std::istream &operator>>(std::istream &is, String &rhs);
bool operator==(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator<(const String &, const String &);
bool operator>(const String &, const String &);
bool operator<=(const String &, const String &);
bool operator>=(const String &, const String &);
#endif
