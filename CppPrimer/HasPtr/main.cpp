#include "HasPtr_ValLike.h"
#include <algorithm>
#include <vector>
#include <string>
#include <initializer_list>
#include <string>
#include <iostream>

// class HasPtr {
// public:
//     friend void swap(HasPtr&, HasPtr&);
//     friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
//     HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
//     {
//     }
//     HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
//     HasPtr& operator=(HasPtr tmp)
//     {
//         this->swap(tmp);
//         return *this;
//     }
//     ~HasPtr() { delete ps; }

//     void swap(HasPtr& rhs)
//     {
//         using std::swap;
//         swap(ps, rhs.ps);
//         swap(i, rhs.i);
//         std::cout << "call swap(HasPtr &rhs)" << std::endl;
//     }

//     void show() const { std::cout << *ps << std::endl; }
// private:
//     std::string* ps;
//     int i;
// };
// void swap(HasPtr& lhs, HasPtr& rhs) {
//     lhs.swap(rhs);
// }
// bool operator<(const HasPtr& lhs, const HasPtr& rhs) {
//     return *lhs.ps < *rhs.ps;
// }

int main()
{
  HasPtr l, r;
  std::cout << (l < r) << std::endl;
  l.swap(r);
  std::vector<std::string> i;
  for (std::string s; std::cin >> s;) {
    i.push_back(s);
  }
  std::vector<HasPtr> vec(i.begin(), i.end());
  std::sort(vec.begin(), vec.end());
  for (auto i : vec)
    std::cout << i << ' ';
  std::cout << std::endl;
}
