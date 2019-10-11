#include "Blob.h"
#include <iostream>

int main()
{
  Blob<int> a, b = {1,2, 3};
  std::cout << (a==b) << std::endl;
  return 0;
}
