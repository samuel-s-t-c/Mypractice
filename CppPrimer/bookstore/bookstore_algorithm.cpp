#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <numeric>
#include "Sales_item.h"

bool compare_isbn(const Sales_item &a, const Sales_item &b)
{
  return a.isbn() >= b.isbn();
}

int main()
{
  // read the datas from standard input
  std::istream_iterator<Sales_item> in_iter(std::cin), end;
  std::vector<Sales_item> trans(in_iter, end);
  std::cout << std::endl;
  std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");
  // sort the transactions in dictionary order of the corresponding isbn;
  std::sort(trans.begin(), trans.end(), compare_isbn);
  // write all the transactions to the standard output
  std::copy(trans.begin(), trans.end(), out_iter);
  std::cout << std::endl;
  auto prev = trans.begin();
  auto iter = trans.begin();
  while (iter != trans.end()) {
    iter = std::find_if(iter, trans.end(), [&](const Sales_item &curr){return curr.isbn() != iter->isbn();});
    Sales_item sum = std::accumulate(prev, iter, Sales_item(prev->isbn()));
    // iter = trans.erase(prev, iter);
    iter = trans.insert(trans.erase(prev, iter), sum);
    ++iter;
    prev = iter;
  }
  std::copy(trans.begin(), trans.end(), out_iter);
  return 0;
}
//vector to hold datas
//algorithm to process; sort and compareIsbn, find and accumulate;

