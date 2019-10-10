#include <cstddef>
#include <iostream>

template<typename T, std::size_t index>
T *begin(T (&arr)[index])
{
  std::cout << "begin\n";
  return arr;
}

template<typename T, std::size_t index>
T *end(T (&arr)[index])
{
  std::cout << "end\n";
  return arr+index;
}

int main()
{
  const char c [] = "123124";
  for(auto iter = begin(c); iter != end(c); ++iter)
    std::cout << *iter;
  std::cout << std::endl;
}
