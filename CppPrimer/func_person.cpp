#include <iostream>
#include "person.h"

std::istream &read(std::istream &is, person &sb)
{
  is >> sb.p_name >> sb.p_address;
  return is;
}

std::ostream &print(std::ostream &os, const person &sb)
{
  os << sb.p_name << " " << sb.p_address;
  return os;
}
