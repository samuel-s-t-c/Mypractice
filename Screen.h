#ifndef SCREENH
#define SCREENH
#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr {
public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);
  Window_mgr();
private:
  std::vector<Screen> screens;
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);
public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, pos num)
    : height(ht), width(wd), contents(num, ' ') { };
  Screen(pos ht, pos wd, char c)
    : height(ht), width(wd), contents(ht*wd, c) { };
  char get() const {return contents[cursor];}
  char get(pos r, pos c) const {return contents[r * width + c];}
  Screen &move(pos r, pos c);
  Screen &set(char c);
  Screen &set(pos, pos, char);
  Screen &display(std::ostream &os) {
    do_display(os); return *this;}
  const Screen &display(std::ostream &os) const {
    do_display(os); return *this;}
  pos size() const {return height * width;}
private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void do_display(std::ostream &os) const {os << contents;}
};

inline Screen &Screen::move(pos r, pos c)
{
  cursor = r * width + c;
  return *this;
}

inline Screen &Screen::set(char c)
{
  contents[cursor] = c;
  return *this;
}

inline Screen &Screen::set(pos row, pos col, char ch)
{
  contents[row * width + col] = ch;
  return *this;
}

inline Window_mgr::Window_mgr()
  : screens{Screen(24, 80, ' ')} { }

void Window_mgr::clear(ScreenIndex i)
{
  Screen &s = screens[i];
  s.contents = std::string(s.height * s.width, ' ');
}

#endif
