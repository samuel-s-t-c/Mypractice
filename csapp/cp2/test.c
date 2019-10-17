#include <stdio.h>

int main()
{
  unsigned char c = 'a';
  printf("0x%.3x\n", c);
  c = c >> 7;
  printf("0x%.3x\n", c);
  return 0;
}
