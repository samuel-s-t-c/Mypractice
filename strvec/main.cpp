#include <vector>
#include "StrVec.h"
#include "MyString.h"

int main()
{
  {
    StrVec vec;
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("first");
    std::cout << "1------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("second");
    std::cout << "2------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("first");
    std::cout << "3------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("second");
    std::cout << "4------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("first");
    std::cout << "5------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("second");
    std::cout << "6------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("first");
    std::cout << "7------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    vec.push_back("second");
    std::cout << "8------\n";
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
  }
}
