#include <iostream>
#include <unordered_set>
#include "Sales_data.h"

int main()
{
  std::unordered_multiset<Sales_data> se;
  while (std::cin)
    se.insert(std::cin);
  for (auto i : se)
    std::cout << i << std::endl;
  return 0;
}
