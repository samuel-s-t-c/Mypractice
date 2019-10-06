#include <iostream>

int main()
{
  struct someclass {
    someclass(double d= 0.0) : i(d) {}
    operator double() {return i;}
    operator float() {return i;}
    long double i;
  };
  someclass obj;
  // int e = obj;
  float e = obj;
}
