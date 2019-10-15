#include <iostream>
#include <sstream>
#include <string>
//  const T &
template <typename T> std::string debug_rep(const T &t)
{
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

// T *
template <typename T> std::string debug_rep(T *p)
{
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}
std::string debug_rep(char *p)
{
  return debug_rep(std::string(p));
}
std::string debug_rep(const char *p)
{
  return debug_rep(std::string(p));
}

//const std::string &
std::string debug_rep(const std::string &p)
{
  return '"' + p + '"';
}

template <class T>
std::ostream& print(std::ostream &os, const T &t)
{
  os << t << "(nonvariadic)| ";
  return os;
}

template <class T, class... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... args)
{
  os << t << "(variadic)| ";
  return print(os, args...);
}

template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args&... rest)
{
  return print(os, debug_rep(rest)...);
}

int main()
{
  int i = 110;
  errorMsg(std::cout, 1, 2, "(123)", "(1fsjh)", &i, 31) << std::endl;
  return 0;
}
