#include <stdio.h>
int main()
{
  int i = 1;
  unsigned long l = (unsigned long)&i;
  unsigned char c = (unsigned char)&i;
  printf("0x%.16lx\n""0x%.16lx\n", l, l%8);
  printf("0x%.16lx\n""0x%.16lx\n", c, c%8);
}
