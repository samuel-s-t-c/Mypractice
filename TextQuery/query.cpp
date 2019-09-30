#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "TextQuery.h"

void runQueries(std::ifstream &infile)
{
  TextQuery tq(infile);
  do {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
  } while (true);
}

int main(int, char ** argc)
{
  std::ifstream ifs(argc[1]);
  runQueries(ifs);
  return 0;
}
