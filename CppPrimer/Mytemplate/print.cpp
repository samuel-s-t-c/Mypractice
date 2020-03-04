#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

template <typename arrayT, std::size_t n>
void print(std::ostream &os, arrayT (&a)[n])
{
  auto num = 0;
  while (num != n) {
    os << a[num] << " ";
    ++num;
  }
}

template <typename C>
void print(const C &obj, std::ostream &os = std::cout)
{
  typename C::size_type max = obj.size();
  typename C::const_iterator iter = obj.begin();
  for (typename C::size_type n = 0; n != max; ++n, (void)++iter)
    os << *iter << " ";
}

#include <string>

int main()
{
  std::vector<char> i {'f','u','c','k'};
  print(i);
  return 0;
}
