#ifndef STRBLOB
#define STRBLOB
#include <string>
class StrBlob {
public:
  //constructors
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  StrBlob(StrBlob &rhs);
  //other member functions

  //destructor
  ~StrBlob();
private:
  unsigned int *refcnt = nullptr;

};
#endif
