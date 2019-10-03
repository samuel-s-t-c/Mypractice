#include <vector>
#include "StrVec.h"
#include "MyString.h"

int main()
{
  {
    std::vector<string> vec;
    vec.push_back("first");
    std::cout << "1------\n";
    vec.push_back("second");
    std::cout << "2------\n";
    vec.push_back("first");
    std::cout << "3------\n";
    vec.push_back("second");
    std::cout << "4------\n";
    vec.push_back("first");
    std::cout << "5------\n";
    vec.push_back("second");
    std::cout << "6------\n";
    vec.push_back("first");
    std::cout << "7------\n";
    vec.push_back("second");
    std::cout << "8------\n";
  }
}
