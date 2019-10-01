#ifndef HASPTR_VALLIKEH
#define HASPTR_VALLIKEH

#include <string>

class HasPtr {
  friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
  HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(0) { }
  HasPtr(const HasPtr &o)
    :ps(new std::string(*o.ps)), i(o.i) { }
  HasPtr &operator=(const HasPtr &rhs)
  {
    auto newp = new std::string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
  }
  ~HasPtr( ) {delete ps;}
private:
  std::string *ps;
  int i;
};
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}
// The functions should be placed into a non-header file
#endif
