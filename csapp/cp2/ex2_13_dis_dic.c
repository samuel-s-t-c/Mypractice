#include <stdio.h>

int bis(int x, int m)
{
  return x | m ;
}

int bic(int x, int m)
{
  return x & (~m);
}

int bool_or(int x, int y)
{
  return bis(x, y);
}

int bool_xor(int x, int y)
{
  return bis(bic(x, y), bic(y, x));
}

int main()
{
  printf("1 | 0: %x\n", bool_or(1, 0));
  printf("0 | 0: %x\n", bool_or(0, 0));
  printf("0 | 1: %x\n", bool_or(0, 1));
  printf("1 | 1: %x\n", bool_or(1, 1));
  printf("1 ^ 0: %x\n", bool_xor(1, 0));
  printf("0 ^ 0: %x\n", bool_xor(0, 0));
  printf("0 ^ 1: %x\n", bool_xor(0, 1));
  printf("1 ^ 1: %x\n", bool_xor(1, 1));
}

