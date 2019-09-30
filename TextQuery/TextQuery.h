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

class TextQuery {
  using line_no = std::vector<std::string>::size_type;
public:
  TextQuery(std::ifstream &infile);
  QueryResult query(const std::string &word);
  void display_map();

private:
  std::shared_ptr<std::vector<std::string>> content;
  std::map<std::string,
           std::shared_ptr<std::set<line_no>>> queryMap;
  static std::string cleanup_str(const std::string&);

};

TextQuery::TextQuery(std::ifstream &infile)
  : content(new std::vector<std::string>)
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

std::string TextQuery::cleanup_str(const std::string&line)
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


QueryResult TextQuery::query(const std::string &word)
{
  static std::shared_ptr<std::set<line_no>> nodata (new std::set<line_no>);
  auto loc = queryMap.find(word);
  if (loc == queryMap.end())
    return QueryResult(cleanup_str(word), content, nodata);
  else
    return QueryResult(cleanup_str(word), content, queryMap[cleanup_str(word)]);
}
#endif
