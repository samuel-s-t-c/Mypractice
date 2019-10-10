#include "Blob.h"
#include <iostream>

template<typename> void fun()
{
  std::cout << "i" << std::endl;
}

int main()
{
  fun<int>();
  return 0;
}
