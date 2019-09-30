#include <iostream>
#include <cstddef>
#include <string>
#include <cctype>
#include "myfunction.h"
#include <vector>
#include <forward_list>
#include <algorithm>
#include <functional>

void elimDups(std::vector<std::string> &words)
{
  std::sort(words.begin(), words.end());
  auto end_unique = std::unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}

bool check_size(const std::string& a, std::string::size_type sz)
{
  return a.size() >= sz;
}

void biggies(std::vector<std::string> &words,
             std::string::size_type sz)
{
  elimDups(words);
  // std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){return a.size() < b.size();});
  // auto f = [sz](const std::string &a){return a.size() >= sz;};
  auto wsz = std::stable_partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
  auto cnt = std::count_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
  std::cout << cnt << ((cnt > 1) ? " words" : " word") << " of length " << sz << " or longer" << std::endl;
  std::for_each(words.begin(), wsz, [](const std::string &a){std::cout << a << ' ';});
  std::cout << std::endl;
}
void insert_after(std::forward_list<std::string> &l,
                  const std::string sought,
                  const std::string added)
{
  bool is_found = false;
  auto prev = l.before_begin();
  auto curr = l.begin();
  while (curr != l.end()) {
    if (*curr == sought) {
      curr = ++l.insert_after(curr, added);
      is_found = true;
    } else {
      prev = curr;
      ++curr;
    }
  }
  if (!is_found)
    l.insert_after(prev, added);
}

std::vector<std::string> &store(std::istream &is,
                                std::vector<std::string> &str_vec)
{
  if (is.good()) {
    std::string str;
    while (getline(is, str)) {
      str_vec.push_back(str += '\n');
    }
    is.clear();
    return str_vec;
  } else {
    return str_vec;
  }
}

std::istream &read(std::istream &is)
{
  std::string str;
  std::string input;
  while (getline(is, input)) {
    str += input + '\n';
  }
  std::cout << str;
  is.clear();
  return is;
}

size_t count_calls()
{
  static size_t ctr = 0;
  return ++ctr;
}

int fact(int val)
{
  int ret = 1;
  while (val > 1)
    ret *= val--;
  return ret;
}

int abs_val(int val)
{
  if (val > 0)
    return val;
  return -val;
}

bool have_capital(const std::string &s)
{
  for (std::string::const_iterator it = s.begin(), end = s.end();
       it != end; ++it) {
    if (isalpha(*it) && *it == toupper(*it))
        return 1;
  }
  return 0;
}

std::string& to_all_lowercase(std::string &s)
{
  for (std::string::iterator it = s.begin(), end = s.end();
       it != end; ++it) {
      *it = tolower(*it);
  }
  return s;
}
