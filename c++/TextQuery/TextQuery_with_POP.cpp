#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <sstream>

typedef std::shared_ptr<std::vector<std::string>> filePtr;
typedef std::vector<std::string>::size_type line_no;
typedef std::map<std::string, std::shared_ptr<std::set<line_no>>> wordMap;

wordMap &buildMap(wordMap &result, const std::string &word, line_no number)
{
  if (!result[word]) {
    result[word].reset(new std::set<line_no>);
  }
  result[word]->insert(number);
  return result;
}

std::string cleanStr(const std::string &str)
{
  std::string o;
  for (auto &i : str) {
    if (ispunct(i))
      o += ' ';
    else o += tolower(i);
  }
  return o;
}

filePtr fileStore(std::ifstream &input, wordMap &result)
{
  filePtr contents(new std::vector<std::string>);
  std::string s;
  line_no number = 0;
  while (std::getline(input, s)) {
    contents->push_back(s);
    std::istringstream wordStr(cleanStr(s));
    std::string word;
    while (wordStr >> word) {
      result = buildMap(result, word, number);
    }
  }
  return contents;
}

std::ostream &print(std::ostream &os, const std::string &word, wordMap& result, filePtr file)
{
  if (!result[word]) {
    os << "No found";
    return os;
  }
  os << word << " : ";
  for (auto i : *result[word])
    os << "\n(line " << i + 1 << " ) " << (*file)[i];
  return os;
}

void runQuery(std::ifstream &input)
{
  wordMap result;
  filePtr file = fileStore(input, result);
  do {
    std::cout << "enter word to lool for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, s, result, file) << std::endl;
  } while (true);
}

int main(int, char **argv)
{
  std::ifstream inFile(argv[1]);
  runQuery(inFile);
  return 0;
}
