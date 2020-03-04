#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "class.h"

int main()
{
  std::ofstream out("input");
  for (int i = 0; i != 10; ++i) {
    int n = i + 1;
    while (n--) {
      int b = i + 1;
      while (b--)
        out << i ;
      out << ' ';
    }
    out << ' ';
  }
  out.close();
  std::ifstream file("input");
  std::string word;
  myclass test(10);
  test.print();
  while (file >> word)
    test(word);
  std::cout << test;
  return 0;
}
