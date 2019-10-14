#include <iostream>
#include <string>

template <class T, class... Args>
void foo(const T &t, const Args& ... rest)
{
  std::cout << sizeof...(Args) << std::endl;
  std::cout << sizeof...(rest) << std::endl;
}

int main()
{
  int i = 0; double d = 3.14; std::string s = "hello";
  foo(i, s, 42, d);
  std::cout << "-----------\n";
  foo(s, 42, "hi");
  std::cout << "-----------\n";
  foo(d,s);
  std::cout << "-----------\n";
  foo("hi");
}
