#include <vector>
#include "StrVec.h"
#include "MyString.h"

int main()
{
  {
    StrVec v1{"22", "23"}, v2{"12", "23"};
    std::cout << (v1 == v2);
    std::cout << std::endl;
  }
}
