#include <iostream>

class numbered {

public:
  numbered() :sn(i){std::cout << sn << std::endl;++i;}
  numbered(const numbered &rhs) :sn(i) {++i;}
  numbered &operator=(const numbered&) = delete;
  std::size_t sn;

private:
  static std::size_t i;

};

std::size_t numbered::i = 0;

void f(numbered &s) {std::cout << s.sn <<std::endl;}

int main()
{
  numbered a, b;
}
