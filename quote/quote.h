#ifndef QUOTEH
#define QUOTEH
#include <string>
#include <iostream>

//************************************************************
//
//                    Quote
//
//************************************************************
class Quote {

public:
  friend double price_total(std::ostream &os, const Quote &obj, std::size_t n);
  //**********constructors**********
  Quote() = default;
  Quote(std::string book, double sales_price)
    : bookNo(book), price(sales_price) { }

  //**********destructor**********
  virtual ~Quote() = default;

  //**********methods**********
  std::string isbn() const {return bookNo;}
  virtual double net_price(std::size_t n) const
  {return n * price;}

private:
  std::string bookNo;
protected:
  double price = 0.0;
};
//**********friends**********
double price_total(std::ostream &os, const Quote &obj, std::size_t n);

//************************************************************
//                    Bulk_Quote
//************************************************************
class Bulk_quote : public Quote {

public:
  Bulk_quote() = default;
  Bulk_quote(std::string book, double sales_price, std::size_t n, double d)
    : Quote(book, sales_price), min_qty(n), discount(d) { }
  double net_price(std::size_t n) const override;

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};
// declarations
// inline definition
double Bulk_quote::net_price(std::size_t n) const
{
  if (n >= min_qty)
    return n * price * (1 - discount);
  else
    return n * price;
}

//************************************************************
//                    Limited_Quote
//************************************************************
class Limited_quote : public Quote {
public:
  Limited_quote() = default;
  Limited_quote(std::string book, double sales_price, std::size_t n, double d)
    : Quote(book, sales_price), max_qty(n), discount(d) { }
  double net_price(std::size_t n) const override;

private:
  std::size_t max_qty = 0;
  double discount = 0.0;

};
double Limited_quote::net_price(std::size_t n) const
{
  if (n <= max_qty)
    return n * price * (1 - discount);
  else
    return (max_qty * (1 - discount) + (n - max_qty)) * price;
}
#endif
