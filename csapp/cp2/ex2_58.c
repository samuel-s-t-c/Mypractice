#include <stdio.h>
#include <assert.h>

int is_little_endian()
{
  int ival = 0xff;
  unsigned char *pc = (unsigned char *) &ival;
  if (pc[0] == 0xff)
    return 1;
  return 0;
}

int main()
{
  assert(is_little_endian());
}
