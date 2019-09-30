#include "Sales_data.h"

class book {
public:
  book()
    : book("No title", "anonymous", 0, "") { std::cout << "default\n";}
  book(std::string tl) : title(tl) { }
  book(std::string tl, std::string oth, double p, std::string sub)
    : title(tl), author(oth), price(p), subject(sub) { std::cout << "take three string\n";}
  book(std::istream &os) {os >> title >> author >> price >> subject;}
private:
  std::string title = "No title";
  std::string author = "anonymous";
  double price = 0;
  std::string subject;
};

int main()
{
  Sales_data i("1", 1, 1);
  std::string s = "2";
  i.combine(s);
  return 0;
}
