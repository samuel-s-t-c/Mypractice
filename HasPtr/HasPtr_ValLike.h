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
  //destrcuctor
  ~HasPtr( ) {delete ps;}
  //operator
  HasPtr &operator=(const HasPtr &rhs)
  {
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }
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
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
  std::cout << "calling ";
  lhs.swap(rhs);
}

inline
std::ostream &operator<<(std::ostream &os, const HasPtr &rhs)
{
  return os << *rhs.ps;
}

// The functions should be placed into a non-header file
#endif
