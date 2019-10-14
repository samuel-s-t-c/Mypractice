#include <iostream>

template <class OS, class T>
OS& print(OS &os, const T &t)
{
  os << t << "(nonvariadic) ";
  return os;
}

template <class OS, class T, class... Args>
OS& print(OS &os, const T &t, const Args&... args)
{
  os << t << "(variadic) ";
  return print(os, args...);
}

class fu{
};

int main()
{
  print(std::cout, 1, 2, "(123)", "(1fsjh)", 1.23, 31) << std::endl;
}
