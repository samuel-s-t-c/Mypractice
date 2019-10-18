#include <stdio.h>
int uadd_ok(unsigned x, unsigned y)
{
  return (x + y) > x;
}

int main()
{
  unsigned x = 0xfff;
  unsigned y = 0xffffff;
  printf("%d\n", uadd_ok(x, y));
  return 0;
}
