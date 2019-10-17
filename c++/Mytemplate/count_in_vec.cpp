#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

template <class T>
std::size_t count(const std::vector<T> &vec, T val)
{
  return std::count_if(vec.begin(), vec.end(), [val](const T& i){return i == val;});
}

template <>
std::size_t count<const char*>(const std::vector<const char*> &vec, const char * val)
{
  return std::count_if(vec.begin(), vec.end(), [val](const char* const &i){return strcmp(i,val)==0;});
}

int main()
{
  std::vector<int> ivec {1, 2, 3, 5, 1, 44, 2, 4, 3, 5};
  std::cout << count(ivec, 2) << std::endl;
  std::vector<std::string> svec {"123", "hello", "hello", "world"};
  std::cout << count(svec, std::string("1")) << std::endl;
  std::vector<double> dvec {1.2, 3, 3, 1, 4, 4.2,44};
  std::cout << count(dvec, 3.0) << std::endl;
  std::vector<const char*> cvec {"123", "e", "123kf", "123"};
  std::cout << count(cvec, "e") << std::endl;
  return 0;
}
