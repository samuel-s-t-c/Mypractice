#ifndef QUERYRESULTH
#define QUERYRESULTH

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <memory>

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  typedef std::vector<std::string>::size_type line_no;
  //**********constructors**********
  QueryResult(const std::string&w,
              std::shared_ptr<std::vector<std::string>> f,
              std::shared_ptr<std::set<line_no>> r)
    : word(w), file(f), lineNumbers(r) { }

  //**********methods**********
  std::set<line_no>::iterator begin() const {
    return lineNumbers->begin();}
  std::set<line_no>::const_iterator cbegin() const {
    return lineNumbers->cbegin();}
  std::set<line_no>::iterator end() const{
    return lineNumbers->end();}
  std::set<line_no>::const_iterator cend() const {
    return lineNumbers->cend();}
  std::shared_ptr<std::vector<std::string>> &get_file() {
    return file;}

private:
  std::string word;
  std::shared_ptr<std::vector<std::string>> file;
  std::shared_ptr<std::set<line_no>> lineNumbers;

};

std::ostream &print(std::ostream &os, const QueryResult &result)
{
  auto n = result.lineNumbers->size();
  os << result.word << " occurs " << n << ((n > 1) ? " times" : " time");
  for (auto i : *result.lineNumbers) {
    os << "\n(line " << i + 1 << " )" << (*result.file)[i];
  }
  return os;
}

#endif
