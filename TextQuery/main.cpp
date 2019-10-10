#include <iostream>
#include <fstream>
#include <string>
#include "Query.h"

int main(int, char **argc)
{
  std::ifstream is(argc[1]);
  std::string i = "1", o = "2";
  Query q = i | o;
  print(std::cout, q.eval(is));
}
