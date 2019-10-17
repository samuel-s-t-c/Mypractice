#ifndef HASPTR_PTRLIKEH
#define HASPTR_PTRLIKEH

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
    :ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
  HasPtr(const HasPtr &o)
    :ps(o.ps), i(o.i) ,use(o.use) {++*use;}
  HasPtr &operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if(--*use) {
      delete ps;
      delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
  }
  ~HasPtr( ) {
    if (--*use) {
      delete ps;
      delete use;
    }
  }
private:
  std::string *ps;
  int i;
  std::size_t *use;
};

#endif
