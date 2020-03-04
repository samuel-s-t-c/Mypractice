#ifndef QUOTEH
#define QUOTEH

#include <string>
#include <iostream>
#include <set>
#include <memory>

//************************************************************
//
//                    Quote
//
//************************************************************
class Quote {

  friend double price_total(std::ostream &os, const Quote &obj, std::size_t n);

public:
  //**********constructors**********
  Quote() {
    #ifndef NDEBUG
    std::cout << "Quote default constructor\n";
    #endif
  }
  Quote(const Quote &obj) : bookNo(obj.bookNo), price(obj.price) {
    #ifndef NDEBUG
    std::cout << "Quote copy constructors\n";
    #endif
  }
  Quote(Quote &&obj) : bookNo(std::move(obj.bookNo)), price(obj.price) {
    #ifndef NDEBUG
    std::cout << "Quote move constructors\n";
    #endif
    obj.bookNo = nullptr;
  }
  Quote(std::string book, double sales_price)
    : bookNo(book), price(sales_price) {
    #ifndef NDEBUG
    std::cout << "Quote initialized constructors\n";
    #endif
  }

  //**********destructor**********
  virtual ~Quote()
  {
    #ifndef NDEBUG
    std::cout << "Quote destructor\n";
    #endif
  }

  //**********operators**********
  Quote &operator=(const Quote &rhs);
  Quote &operator=(Quote &&rhs);

  //**********methods**********
  std::string isbn() const {return bookNo;}
  virtual double net_price(std::size_t n) const {return n * price;}
  virtual void debug() const {
    std::cout << "bookNo: " << bookNo << " # price: " << price;}
  virtual Quote *clone() const &{return new Quote(*this);}
  virtual Quote *clone() && {return new Quote(std::move(*this));}

private:
  std::string bookNo;
protected:
  double price = 0.0;
};
//**********friends**********
double price_total(std::ostream &os, const Quote &obj, std::size_t n);

//**********inline definitions**********
//**********operators**********
inline
Quote &Quote::operator=(const Quote &rhs)
{
  #ifndef NDEBUG
  std::cout << "Quote copy-assignment operator\n";
  #endif
  bookNo = rhs.bookNo;
  price = rhs.price;
  return *this;
}

inline
Quote &Quote::operator=(Quote &&rhs)
{
  #ifndef NDEBUG
  std::cout << "Quote move-assignment operator\n";
  #endif
  if (this != &rhs) {
    bookNo = std::move(rhs.bookNo);
    price = rhs.price;
  }
  return *this;
}


//************************************************************
//                    Disc_quote
//                 (Abstract Base Class)
//************************************************************
class Disc_quote : public Quote {

public:
  //**********constructors**********
  Disc_quote() : Quote() {
    #ifndef NDEBUG
    std::cout << "Disc_quote default constructor\n";
    #endif
  }
  Disc_quote(std::string book, double p, std::size_t n, double d)
    : Quote(book, p), quantity(n), discount(d) {
    #ifndef NDEBUG
    std::cout << "Disc_quote initialized constructors\n";
    #endif
  }
  Disc_quote(const Disc_quote &obj) : Quote(obj), quantity(obj.quantity), discount(obj.discount) {
    #ifndef NDEBUG
    std::cout << "Disc_quote copy constructor\n";
    #endif
  }
  Disc_quote(Disc_quote &&obj) : Quote(std::move(obj)), quantity(obj.quantity), discount(obj.discount) {
    #ifndef NDEBUG
    std::cout << "Disc_quote move constructor\n";
    #endif
  }

  //**********destructor**********
  virtual ~Disc_quote()
  {
    #ifndef NDEBUG
    std::cout << "Disc_quote destructor\n";
    #endif
  }

  //**********operators**********
  Disc_quote &operator=(const Disc_quote &rhs) {
    #ifndef NDEBUG
    std::cout << "Disc_quote copy-assignment operator\n";
    #endif
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    price = rhs.price;
    return *this;
  }
  Disc_quote &operator=(Disc_quote &&rhs){
    #ifndef NDEBUG
    std::cout << "Disc_quote move-assignment operator\n";
    #endif
    Quote::operator=(std::move(rhs));
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }

  //**********methods**********
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
  //**********constructors**********
  Bulk_quote() : Disc_quote() {
    #ifndef NDEBUG
    std::cout << "Bulk_quote default constructor\n";
    #endif
  }

  Bulk_quote(std::string book, double sales_price, std::size_t n, double d)
    : Disc_quote(book, sales_price, n, d) {
    #ifndef NDEBUG
    std::cout << "Bulk_quote initialized constructors\n";
    #endif
  }

  Bulk_quote(const Bulk_quote &obj) : Disc_quote(obj) {
    #ifndef NDEBUG
    std::cout << "Bulk_quote copy constructor\n";
    #endif
  }
  Bulk_quote(Bulk_quote &&obj) : Disc_quote(std::move(obj)) {
    #ifndef NDEBUG
    std::cout << "Bulk_quote move constructor\n";
    #endif
  }

  //**********destructor**********
  virtual ~Bulk_quote()
  {
    #ifndef NDEBUG
    std::cout << "Bulk_quote destructor\n";
    #endif
  }

  //**********operators**********
  Bulk_quote &operator=(const Bulk_quote &rhs) {
    #ifndef NDEBUG
    std::cout << "Bulk_quote copy-assignment operator\n";
    #endif
    Disc_quote::operator=(rhs);
    return *this;
  }
  Bulk_quote &operator=(Bulk_quote &&rhs) {
    #ifndef NDEBUG
    std::cout << "Bulk_quote move-assignment operator\n";
    #endif
    Disc_quote::operator=(std::move(rhs));
    return *this;
  }

  //**********methods**********
  virtual double net_price(std::size_t n) const override;
  virtual void debug() const override;
  virtual Bulk_quote *clone() const & override{return new Bulk_quote(*this);}
  virtual Bulk_quote *clone() && override {return new Bulk_quote(std::move(*this));}

};

//**********declarations**********

//**********inline definition**********

inline
double Bulk_quote::net_price(std::size_t n) const
{
  if (n >= quantity)
    return n * price * (1 - discount);
  else
    return n * price;
}

inline
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
  //**********constructors**********
  Limited_quote() : Disc_quote() {
    #ifndef NDEBUG
    std::cout << "Limited_quote default constructor\n";
    #endif
  }
  Limited_quote(std::string book, double sales_price, std::size_t n, double d)
    : Disc_quote(book, sales_price, n, d) {
    #ifndef NDEBUG
    std::cout << "Limited_quote initialized constructors\n";
    #endif
  }
  Limited_quote(const Limited_quote &obj) : Disc_quote(obj) {
    #ifndef NDEBUG
    std::cout << "Limited_quote copy constructor\n";
    #endif
  }
  Limited_quote(Limited_quote &&obj) : Disc_quote(std::move(obj)) {
    #ifndef NDEBUG
    std::cout << "Limited_quote move constructor\n";
    #endif
  }

  //**********destructor**********
  virtual ~Limited_quote()
  {
    #ifndef NDEBUG
    std::cout << "Limited_quote destructor\n";
    #endif
  }

  //**********operators**********
  Limited_quote &operator=(const Limited_quote &rhs) {
    #ifndef NDEBUG
    std::cout << "Limited_quote copy-assignment operator\n";
    #endif
    Disc_quote::operator=(rhs);
    return *this;
  }
  Limited_quote &operator=(Limited_quote &&rhs) {
    #ifndef NDEBUG
    std::cout << "Limited_quote move-assignment operator\n";
    #endif
    Disc_quote::operator=(std::move(rhs));
    return *this;
  }

  //**********methods**********
  virtual double net_price(std::size_t n) const override;
  virtual void debug() const override;
  virtual Limited_quote *clone() const & override{return new Limited_quote(*this);}
  virtual Limited_quote *clone() && override {return new Limited_quote(std::move(*this));}

};

//**********inline definition**********
//**********methods**********
inline
double Limited_quote::net_price(std::size_t n) const
{
  if (n <= quantity)
    return n * price * (1 - discount);
  else
    return (quantity * (1 - discount) + (n - quantity)) * price;
}

inline
void Limited_quote::debug() const
{
  std::cout << "bookNo: " << isbn() << " | price: " << price
            << " | max_qtr: " << quantity << " | discount: " << discount;
}

//************************************************************
//
//                    Basket
//
//************************************************************

class Basket {

public:
  //**********methods**********
  void add_item(const Quote &obj);
  void add_item(Quote &&obj);
  double total_receipt(std::ostream &os) const;

private:
  static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {return lhs->isbn() < rhs->isbn();}
  std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items {compare};
};

//**********inline definitions**********
//**********methods**********
inline
void Basket::add_item(const Quote &obj)
{
  items.insert(std::shared_ptr<Quote>(obj.clone()));
}

inline
void Basket::add_item(Quote &&obj)
{
  items.insert(std::shared_ptr<Quote>(std::move(obj).clone()));
}

inline
double Basket::total_receipt(std::ostream &os) const
{
  double sum = 0.0;
  for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    sum += price_total(os, **iter, items.count(*iter));
  os << "Total Sale: " << sum ;
  return sum;
}

#endif
