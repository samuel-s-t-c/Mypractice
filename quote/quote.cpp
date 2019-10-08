
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
  // Quote o ("Quote", 1);
  Bulk_quote o ("Bulk_quote", 1, 1, 0.1);
  // Limited_quote o ("Limited_quote", 1, 1, 0.1);
  // Disc_quote o ("Disc_quote", 1, 1, 0.1);
  price_total(std::cout, o, 2);
  std::cout << std::endl;
}
