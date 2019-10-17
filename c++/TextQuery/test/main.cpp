#include <iostream>
#include <fstream>
#include "Query.h"

void runquery(std::ifstream &is)
{
}

int main(int, char ** argc)
{
  std::ifstream is(argc[1]);
  runquery(is);
}
