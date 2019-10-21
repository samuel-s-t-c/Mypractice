#include <assert.h>
typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum)
{
  return ((int)(word << ((3 - bytenum) << 3))) >> 24;
}

int main()
{
  assert(xbyte(0xff0ff00f, 3) == (int)0xffffffff);
  assert(xbyte(0xff0ff00f, 2) == (int)0x0000000f);
  assert(xbyte(0xff0ff00f, 1) == (int)0xfffffff0);
  assert(xbyte(0xff0ff00f, 0) == (int)0x0000000f);
  return 0;
}
