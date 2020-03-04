template <typename iter, typename val>
iter find(const iter &beg, const iter &end,const val &sought)
{
  for (auto i = beg; i != end; ++i) {
    if (*i == sought)
      return i;
  }
  return end;
}

#include <vector>
#include <list>
#include <string>
#include <iostream>

int main()
{
  std::vector<int> ivec {1, 2, 3, 4, 5, 6, 7};
  std::list<std::string> slis {"12", "23", "34", "45"};
  std::cout << *find(ivec.begin(), ivec.end(), 2) << std::endl;
  auto i = find(slis.begin(), slis.end(), "312");
  std::cout << ((i == slis.end()) ? "false" : (*i)) << std::endl;
}
