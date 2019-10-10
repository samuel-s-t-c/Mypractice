#include <iostream>

template <typename arrayT, std::size_t n>
void print(std::ostream &os, arrayT (&a)[n])
{
  auto num = 0;
  while (num != n) {
    os << a[num] << " ";
    ++num;
  }
}

#include <string>

int main()
{
  std::string i [] ={"12344", "", "123124sdafk", "12oied1jo"};
  print(std::cout, i);
  return 0;
}
