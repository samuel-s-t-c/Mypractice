#include <string>
#include <iostream>

class book {
  friend std::ostream &operator<<(std::ostream &lhs, const book &rhs);
  friend std::istream &operator>>(std::istream &lhs, book &rhs);
  friend bool operator==(const book &lhs, const book &rhs);
  friend bool operator!=(const book &lhs, const book &rhs);
public:
  book() : book("nil", "nil", "anonymous", 0) { }
  book(std::string tl) : title(tl) { }
  book(std::string no, std::string tl, std::string name , double p)
    : ISBN(no), title(tl), author(name), price(p) { }
  book(std::istream &os) {os >> ISBN >> title >> author >> price;}
private:
  std::string ISBN = "nil";
  std::string title = "nil";
  std::string author = "anonymous";
  double price = 0;
};
// declarations of friend functions
std::ostream &operator<<(std::ostream &lhs, const book &rhs);
std::istream &operator>>(std::istream &lhs, const book &rhs);
bool operator==(const book &lhs, const book &rhs);
bool operator!=(const book &lhs, const book &rhs);

// implements of friend functions (may not in the header)

std::ostream &operator<<(std::ostream &lhs, const book &rhs)
{
  lhs << rhs.ISBN << " " << rhs.title << " "
      << rhs.author << " " << rhs.price << " ";
  return lhs;
}

std::istream &operator>>(std::istream &lhs, book &rhs)
{
  book temp = rhs;
  lhs >> rhs.ISBN >> rhs.title >> rhs.author >> rhs.price;
  if (!lhs)
    rhs = std::move(temp);
  return lhs;
}

bool operator==(const book &lhs, const book &rhs)
{
  return lhs.ISBN == rhs.ISBN;
}

bool operator!=(const book &lhs, const book &rhs)
{
  return lhs.ISBN != rhs.ISBN;
}
