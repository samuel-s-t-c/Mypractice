#include <tuple>
#include <string>
#include <vector>
#include <utility>


int main()
{
  std::tuple<int, int, int> threeInt(10, 20, 30);
  std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> val;
  return 0;
}
