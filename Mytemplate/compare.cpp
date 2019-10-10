#include <iostream>

template <class t>
bool compare(const t &lhs, const t &rhs)
{
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}

int main()
{
  std::cout << compare(1, 2) << std::endl;
  std::cout << compare(1.1, 2.2) << std::endl;
  return 0;
}
