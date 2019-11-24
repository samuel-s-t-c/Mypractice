#include <stdio.h>

void f(void);

int y = 22;
int x = 11;
int main()
{
  f();
  printf("x = 0x%x y = 0x%x \n", x, y);
  return 0;
}
