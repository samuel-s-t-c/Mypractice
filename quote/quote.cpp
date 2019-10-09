
#include "quote.h"

//**********friends**********
double price_total(std::ostream &os, const Quote &obj, std::size_t n)
{
  double ret = obj.net_price(n);
  os << "ISBN: " << obj.bookNo
     << " # sold: " << n << " total due: " << ret << std::endl;
  obj.debug();
  return ret;
}

int main()
{
  Bulk_quote p("Bulk", 2, 1, 0.2);
  price_total(std::cout , p, 1);
  std::cout << std::endl;
}
