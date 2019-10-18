#include <stdio.h>

int tadd_ok(int x, int y)
{
  if ((x > 0) && (y > 0))
    return x + y > 0;
  if ((x < 0) && (y < 0))
    return x + y < 0;
  return  1;
}

int main()
{
  printf("%d\n", tadd_ok(1,2));
  printf("%d\n", tadd_ok(0x7fffffff,2));
}
