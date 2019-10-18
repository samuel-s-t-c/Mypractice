#include <iostream>

int main()
{
  int x = 0xfffffff8;
  int y = -x;
  std::cout << x << " " << y << std::endl;
  std::cout << y - x << std::endl;
}
