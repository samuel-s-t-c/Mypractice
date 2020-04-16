#include <iostream>

template <typename T> class Base
{
public:
  Base(std::string s) {std::cout << s << std::endl;}
};

extern template class Base<int>;

void func()
{
  Base<int> a("func");
}
