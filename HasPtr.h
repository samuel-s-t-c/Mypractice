#ifndef HASPTRH
#define HASPTRH

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr &o)
    :ps(new std::string())
  {
    *ps = *o.ps;
    i = o.i;
  }
private:
  std::string *ps;
  int i;
};

#endif
