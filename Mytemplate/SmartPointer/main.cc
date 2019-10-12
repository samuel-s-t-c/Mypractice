#include <vector>
#include <iostream>
#include "Blob.h"
#include "shared_ptr.h"

int main()
{
  Blob<int> b = {1,2,3,4};
  {
    auto p = b;
    b = std::move(p);
  }
  for(auto i : b)
    std::cout << i << std::endl;
  return 0;
}
