#include <stdio.h>
#include <stdint.h>

int32_t div16(int32_t input)
{
  return (input + ((input >> 31) & 0xf)) >> 4;
}

int main()
{
  int i = 17;
  printf("17/16 = %d or %d\n", div16(i), (i/16));
  printf("-17/16 = %d or %d\n", div16(-i), (-i/16));
}
