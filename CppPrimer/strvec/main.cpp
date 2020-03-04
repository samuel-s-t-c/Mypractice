#include <vector>
#include "StrVec.h"
#include <string>
#include "MyString.h"
#include <iostream>
#include <utility>

int main()
{
  StrVec vec {"123"};
  vec.emplace_back(10, 'v');
  for (auto &i :vec)
    std::cout << i << std::endl;
  std::cout << std::endl;
  return 0;
}
