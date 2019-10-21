#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
  if (i >= sizeof(x))
    return x;

  unsigned mark = 0xff;
  unsigned cover = b;

  x = (x & ~(mark << (i << 3))) | (cover << (i << 3));

  return x;
}

int main()
{
  assert(replace_byte(0x12345678, 0, 0xab) == 0x123456ab);
  assert(replace_byte(0x12345678, 2, 0xab) == 0x12ab5678);
  assert(replace_byte(0x12345678, 4, 0xab) == 0x12345678);
  assert(replace_byte(0x12345678, -1, 0xab) == 0x12345678);
  return 0;
}
