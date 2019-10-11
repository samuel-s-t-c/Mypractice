#include <string>
#include <iostream>
template <std::string::size_type, std::string::size_type> class Screen;
template <std::string::size_type H, std::string::size_type W> std::ostream &operator<<(std::ostream &os, const Screen<H, W> &obj);
template <std::string::size_type H, std::string::size_type W> std::istream &operator>>(std::istream &is, const Screen<H, W> &obj);

template <std::string::size_type H, std::string::size_type W>
class Screen {
  friend std::ostream &operator<<<H, W>(std::ostream &is, const Screen<H, W> &obj);
  friend std::istream &operator>><H, W>(std::istream &is, const Screen<H, W> &obj);

public:
  using pos = std::string::size_type;
  Screen(char c = ' ') : contents(H*W, c) {}
  Screen(pos n) : contents(n, ' ') {}
  char get() const {return contents[cursor];}
  char get(pos r, pos c) const {return contents[r * W + c];}
  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos r, pos c, char ch);
private:
  pos cursor = 0;
  std::string contents;
};

template <std::string::size_type H, std::string::size_type W>
Screen<H, W> &Screen<H, W>::move(pos r, pos c)
{
  cursor = r * W + c;
  return *this;
}

template <std::string::size_type H, std::string::size_type W>
Screen<H, W> &Screen<H, W>::set(char c)
{
  contents[cursor++] = c;
  cursor = std::min(cursor, H * W);
  return *this;
}

template <std::string::size_type H, std::string::size_type W>
Screen<H, W> &Screen<H, W>::set(pos r, pos c, char ch)
{
  contents[r * W + c] = ch;
  return *this;
}

template <std::string::size_type H, std::string::size_type W>
std::ostream &operator<<(std::ostream &os, const Screen<H, W> &obj)
{
  using pos = typename Screen<H, W>::pos;
  for (pos n = 0; n != W; ++n) os << '_';
  os << std::endl;
  for (pos r = 0; r != H; ++r) {
    os << '|';
    for (pos c = 0; c != W; ++c) {
      os << obj.get(r, c);
    }
    os << '|'<<std::endl;
  }
  for (pos n = 0; n != W; ++n) os << '_';
  os << std::endl;
  return os;
}

template <std::string::size_type H, std::string::size_type W>
std::istream &operator>>(std::istream &is, Screen<H, W> &obj)
{
  std::string input;
  std::getline(is, input);
  for (char ch : input)
    obj.set(ch);
  return is;
}

int main()
{
  Screen<30, 60> s(' ');
  std::cout << s;
  while(std::cin >> s)
    std::cout << s;
}
