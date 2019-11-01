#include <stdio.h>

void subsubf()
{
  printf("Deepest\n");
}

void subf()
{
  printf("subfunction\n");
  subsubf();
}

int main()
{
  printf("main\n");
  subf();
  return 0;
}
