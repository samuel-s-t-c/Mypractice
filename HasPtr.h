#ifndef HASPTRH
#define HASPTRH

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr &o)
    :ps(new std::string(*o.ps)), i(o.i) { }
  HasPtr &operator=(const HasPtr &rhs)
  {
    if (this == &rhs)
      return *this;
    delete ps;
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    return *this;
  }
  ~HasPtr( ) {delete ps;}
private:
  std::string *ps;
  int i;
};

#endif
