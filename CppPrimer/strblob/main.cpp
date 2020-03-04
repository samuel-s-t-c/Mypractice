#include "StrBlob.h"
#include <vector>

class po {
public:
  po() = default;
  po(StrBlobPtr &ptr) : p2ptr(&ptr) { }
  StrBlobPtr* operator->()
  {
    return p2ptr;
  }
private:
  StrBlobPtr * p2ptr;
};

int main()
{
  po p;
}
