
#include "quote.h"

//**********friends**********
double price_total(std::ostream &os, const Quote &obj, std::size_t n)
{
  double ret = obj.net_price(n);
  os << "ISBN: " << obj.bookNo
     << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}

#include <vector>
#include <memory>

int main()
{
  Bulk_quote i1("B", 1, 1, 0.1);
  Limited_quote i2("A", 1, 1, 0.1);
  Basket vec;
  vec.add_item(i1);
  vec.add_item(i1);
  vec.add_item(i2);
  vec.add_item(i2);
  vec.total_receipt(std::cout);
  std::cout << std::endl;
}
