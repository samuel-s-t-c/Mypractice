#ifndef MYCLASSH
#define MYCLASSH

#include <iostream>
#include <string>
#include <map>

class myclass {
  friend std::ostream &operator<<(std::ostream &os, const myclass &rhs);
public:
  myclass(std::size_t b = 0, std::size_t l = 0) : bound(b), low(l)
  {
    if (l > b)
      bound = low = 0;
  }
  void operator()(const std::string &str)
  {
    if (str.size() <= bound && str.size() >= low) {
      ++cnt[str.size()];
    }
  }
  void print() {std::cout << low << " " << bound << std::endl;}
private:
  std::size_t bound;
  std::size_t low;
  std::map<std::size_t, std::size_t> cnt;
};

std::ostream &operator<<(std::ostream &os, const myclass &rhs)
{
  for (auto i : rhs.cnt) {
    os << i.first << " " << i.second << std::endl;
  }
  return os;
}

#endif
