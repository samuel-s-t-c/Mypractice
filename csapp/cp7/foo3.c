#include <stdio.h>

void f(void);

int x;

int main()
{
  x = 1;
  printf("x = %d\n", x);
  f();
  printf("x = %d\n", x);
  return 0;
}
