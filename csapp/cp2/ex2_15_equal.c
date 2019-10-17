#include <stdio.h>

int equal(int x, int y)
{
  return !(x ^ y);
}

int main()
{
  printf("%d\n",equal(1,1));
  printf("%d\n",equal(0,1));
}
