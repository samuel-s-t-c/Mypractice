#include <iostream>

class Father {
protected:
  char f = 'f';
public:
  virtual void show() {
    std::cout << f << std::endl;
  }
};

class Son : public Father {
protected:
  char s = 's';
public:
  virtual void show() {
    std::cout << s << std::endl;
  }
};

int main()
{
  Son b;
  Father &a = b;
  a.show(); b.show();
  a = b;
  a.show(); b.show();
}
