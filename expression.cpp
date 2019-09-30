#include <string>
#include <iostream>
#include <stack>
#include <vector>

std::vector<std::string> transform(const std::string &str)
{
  std::string::size_type index = 0;
  std::vector<std::string> str_vec;
  static char nums [] = "0123456789";
  static char opert [] = "+-/*";
  while ((index = str.find_first_of(nums, index)) != std::string::npos) {
    str_vec.push_back(std::to_string(std::stod(str.substr(index))));
    index = str.find_first_of(opert, index);
    str_vec.push_back(std::string(&str[index], 1));
  }
  return str_vec;
}

double cal(const std::string &s)
{
  std::size_t index = s.find_first_of("+-*/");
  if (index == std::string::npos)
    return stod(s);
  char op = s[index];
  std::size_t p = s.size() - 1;
  p = s.find_last_of("0123456789", p);
  double first = std::stod(s.substr(p));
  --p;
  while (p <= s.size() && (p = s.find_last_of("0123456789", p)) != std::string::npos) {
    double next = std::stod(s.substr(p));
    p = s.find_last_not_of("0123456789", p);
    // std::cout << next << std::endl;
    switch (op) {
    case '+':
      first += next;
      break;
    case '-':
      first -= next;
      break;
    case '*':
      first *= next;
      break;
    case '/':
      first /= next;
      break;
    }
  }
  return first;
}

double f(const std::string & str)
{
  unsigned ob = 0;
  std::stack<char> cs;
  std::string::const_reverse_iterator rend = str.rend();
  for (std::string::const_reverse_iterator rit = str.rbegin(); rit != rend; ++rit) {
    if (*rit == ')') {
      ++ob;
      cs.push(*rit);
    } else if (*rit == '(') {
      if (ob) {
        --ob;
        std::string s;
        while (cs.top() != ')') {
          s.push_back(cs.top());
          cs.pop();
        }
        cs.pop();
        std::string result = std::to_string(cal(s));
        for (std::string::reverse_iterator i = result.rbegin();
             i != result.rend(); ++i)
          cs.push(*i);
      }else
        continue;
    } else {
      cs.push(*rit);
    }
  }
  std::string s;
  while (!cs.empty()) {
    s.push_back(cs.top());
    cs.pop();
  }
  std::cout << s << std::endl;
  return cal(s);
}

int main ()
{
  std::string str = "(1.2+(1/1))";
  std::vector<std::string> svec = transform(str);
  for (auto i : svec)
  std::cout << i << std::endl;
  str = "2+1";
  // std::cout << str.find_last_of("0123456789", 1) << std::endl;
}
