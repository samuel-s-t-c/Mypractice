#include <iostream>

template <class T, class F = std::less<T>>
int compare(const T &lhs, const T &rhs, F f = F())
{
  if (f(lhs, rhs)) return -1;
  if (f(rhs, lhs)) return 1;
  return 0;
}

int main()
{
  std::cout << compare(1,2) << std::endl;
  std::cout << compare(1,2,[](int a,int b){return a>b;}) << std::endl;
  return 0;
}
