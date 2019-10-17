#include <cstddef>

template<typename T, std::size_t n>
constexpr std::size_t size(const T (&a)[n])
{return n;}

#include <iostream>

int main()
{
  char i [] = "123124";
  std::cout << size(i);
}
