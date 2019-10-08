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
  virtual void debug() const
  {std::cout << "bookNo: " << bookNo << " # price: " << price;}

private:
  std::string bookNo;
protected:
  double price = 0.0;
};
//**********friends**********
double price_total(std::ostream &os, const Quote &obj, std::size_t n);

//************************************************************
//                    Disc_quote
//                 (Abstract Base Class)
//************************************************************
class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(std::string book, double p, std::size_t n, double d)
    : Quote(book, p), quantity(n), discount(d) { }
  double net_price(std::size_t n) const = 0;
  void debug() const = 0;

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

//************************************************************
//                    Bulk_Quote
//************************************************************
class Bulk_quote : public Disc_quote {

public:
  Bulk_quote() = default;
  Bulk_quote(std::string book, double sales_price, std::size_t n, double d)
    : Disc_quote(book, sales_price, n, d) { }
  double net_price(std::size_t n) const override;
  void debug() const override;

};
// declarations
// inline definition
double Bulk_quote::net_price(std::size_t n) const
{
  if (n >= quantity)
    return n * price * (1 - discount);
  else
    return n * price;
}

void Bulk_quote::debug() const
{
  std::cout << "bookNo: " << isbn() << " | price: " << price
            << " | min_qtr: " << quantity << " | discount: " << discount;
}

//************************************************************
//                    Limited_Quote
//************************************************************
class Limited_quote : public Disc_quote {
public:
  Limited_quote() = default;
  Limited_quote(std::string book, double sales_price, std::size_t n, double d)
    : Disc_quote(book, sales_price, n, d) { }
  double net_price(std::size_t n) const override;
  void debug() const override;

};

double Limited_quote::net_price(std::size_t n) const
{
  if (n <= quantity)
    return n * price * (1 - discount);
  else
    return (quantity * (1 - discount) + (n - quantity)) * price;
}

void Limited_quote::debug() const
{
  std::cout << "bookNo: " << isbn() << " | price: " << price
            << " | max_qtr: " << quantity << " | discount: " << discount;
}

#endif
