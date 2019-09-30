#include <memory>
#include <string>
#include <iostream>
#include <iterator>

void foo(std::size_t n)
{
  std::allocator<std::string> alloc;
  std::string * const p = alloc.allocate(n);
  std::istream_iterator<std::string> str_it(std::cin), str_end;
  auto q = std::uninitialized_copy(str_it, str_end, p);
  while (q != p) {
    std::cout << *--q << " ";
    alloc.destroy(q);
  }
  alloc.deallocate(p, n);
}

int main()
{
  foo(5);
}
