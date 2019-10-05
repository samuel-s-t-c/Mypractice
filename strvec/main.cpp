#include <vector>
#include "StrVec.h"
#include <string>
#include "MyString.h"
#include <iostream>
#include <utility>

int main()
{
  std::string s = {"123"};
  std::string *p = &s;
  std::cout << p[1] << std::endl;
  return 0;
}
