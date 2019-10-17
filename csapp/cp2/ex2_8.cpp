#include <iostream>
#include <bitset>

int main()
{
  std::bitset<8> a(105);
  std::bitset<8> b(85);
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "~a " << ~a << " \n   10010110" << std::endl;
  std::cout << "~b " << ~b << " \n   10101010" << std::endl;
  std::cout << "a&b " << (a&b) << " \n    01000001" << std::endl;
  std::cout << "a|b " << (a|b) << " \n    01111101" << std::endl;
  std::cout << "a^b " << (a^b) << " \n    00111100" << std::endl;
}
