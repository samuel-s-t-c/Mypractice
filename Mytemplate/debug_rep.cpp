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
  std::cout << "T*\n";
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}
template <>
std::string debug_rep<char>(char *p)
{
  return debug_rep(std::string(p));
}
template<>
std::string debug_rep<const char>(const char *p)
{
  return debug_rep(std::string(p));
}

//const std::string &
std::string debug_rep(const std::string &p)
{
  std::cout << "const string &\n";
  return '"' + p + '"';
}

int main()
{
  char s[] = "123142";
  std::cout << debug_rep(s) << std::endl;
  return 0;
}
