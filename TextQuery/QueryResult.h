#ifndef QUERYRESULTH
#define QUERYRESULTH

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <memory>

class QueryResult {
  typedef std::vector<std::string>::size_type line_no;
  friend std::ostream &print(std::ostream &, const QueryResult &);
public:
  QueryResult(const std::string&w,
              std::shared_ptr<std::vector<std::string>> f,
              std::shared_ptr<std::set<line_no>> r)
    : word(w), file(f), lineNumbers(r) { }
  std::set<line_no>::iterator begin()
  {return lineNumbers->begin();}
  std::set<line_no>::const_iterator begin() const
  {return lineNumbers->cbegin();}
  std::set<line_no>::iterator end()
  {return lineNumbers->end();}
  std::set<line_no>::const_iterator end() const
  {return lineNumbers->cend();}
  std::shared_ptr<std::vector<std::string>> &get_file()
  {return file;}
private:
  std::string word;
  std::shared_ptr<std::vector<std::string>> file;
  std::shared_ptr<std::set<line_no>> lineNumbers;

};

std::ostream &print(std::ostream &os, const QueryResult &result)
{
  os << "The query of "<< result.word << " is :";
  for (auto i : *result.lineNumbers) {
    os << "\n(line " << i << " )" << (*result.file)[i];
  }
  return os;
}

#endif
