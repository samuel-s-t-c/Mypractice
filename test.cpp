#include <iostream>
#include <vector>

template <typename T>
void f(T &);

int main()
{
  using t = int&;
  int i = 3;
  t &p = i;
  f(p);
}
