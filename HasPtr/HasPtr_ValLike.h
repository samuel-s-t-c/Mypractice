#ifndef HASPTR_VALLIKEH
#define HASPTR_VALLIKEH

#include <string>
#include <iostream>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);
  friend std::ostream &operator<<(std::ostream &os, const HasPtr &rhs);
public:
  //constructor
  HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(1) { }
  HasPtr(const HasPtr &o)
    :ps(new std::string(*o.ps)), i(o.i) { }
  HasPtr(HasPtr &&o) noexcept
    :ps(o.ps), i(o.i) {o.ps = nullptr;}
  //destrcuctor
  ~HasPtr( ) {delete ps;}
  //operator
  HasPtr &operator=(HasPtr rhs);
  bool operator<(const HasPtr &rhs)
  {
    return *this->ps < *rhs.ps;
  }
  //
  void swap(HasPtr &rhs)
  {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
    std::cout << "lhs.swap(rhs)\n";
  }
private:
  std::string *ps;
  int i;
};
//functions implement;
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
  std::cout << "calling ";
  lhs.swap(rhs);
}

HasPtr &HasPtr::operator=(HasPtr rhs)
{
  ::swap(*this, rhs);
  return *this;
}

inline
std::ostream &operator<<(std::ostream &os, const HasPtr &rhs)
{
  return os << *rhs.ps;
}

// The functions should be placed into a non-header file
#endif
