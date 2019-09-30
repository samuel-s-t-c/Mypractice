#ifndef MYFUNCTIONH
#define MYFUNCTIONH

#include <cstddef>
#include <string>
#include <vector>
#include <forward_list>

void biggies(std::vector<std::string> &words,
             std::string::size_type sz);
bool check_size(const std::string& a, std::string::size_type sz);
void elimDups(std::vector<std::string> &words);
void insert_after(std::forward_list<std::string> &l,
                  const std::string sought,
                  const std::string added);
std::vector<std::string> &store(std::istream&, std::vector<std::string>&);
std::istream &read(std::istream &);
size_t count_calls();
int fact(int);
int abs_val(int);
bool have_capital(const std::string&);
std::string &to_all_lowercase(std::string&);
#endif
