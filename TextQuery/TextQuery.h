#ifndef TEXTQUERYH
#define TEXTQUERYH

#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "QueryResult.h"

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) {}
  template <typename T> void operator()(T *p) const {
    os << "Deleting the shared_ptr" << std::endl;
    delete p;
  }
private:
  std::ostream &os;
};
class TextQuery {
public:
  using line_no = std::vector<std::string>::size_type;
  TextQuery(std::ifstream &infile);
  QueryResult query(const std::string &word) const;
  void display_map();

private:
  std::shared_ptr<std::vector<std::string>> content;
  std::map<std::string, std::shared_ptr<std::set<line_no>>> queryMap;
  std::string cleanup_str(const std::string&) const;

};

TextQuery::TextQuery(std::ifstream &infile)
  : content(new std::vector<std::string>, DebugDelete())
{
  std::string line;
  line_no number = 0;
  while (std::getline(infile, line)) {
    content->push_back(line);
    std::istringstream words(cleanup_str(line));
    std::string word;
    while (words >> word) {
      if (!queryMap[word])
        queryMap[word].reset(new std::set<line_no>);
      queryMap[word]->insert(number);
    }
    ++number;
  }
}

inline
std::string TextQuery::cleanup_str(const std::string &line) const
{
  std::string output;
  for (auto &i : line) {
    if (ispunct(i))
      output += ' ';
    else
      output += tolower(i);
  }
  return output;
}

inline
QueryResult TextQuery::query(const std::string &word) const
{
  static std::shared_ptr<std::set<line_no>> nodata (new std::set<line_no>);
  auto loc = queryMap.find(cleanup_str(word));
  if (loc == queryMap.end())
    return QueryResult(word, content, nodata);
  else
    return QueryResult(word, content, queryMap.at(cleanup_str(word)));
}
#endif
