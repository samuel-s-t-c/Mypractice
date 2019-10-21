
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

unsigned srl(unsigned x, int k)
{
  unsigned xsra = (int) x >> k;
  unsigned mark = (2 << (8*sizeof(int)- k - 1)) - 1;
  return xsra & mark;
}

unsigned sra(int x, int k)
{
  int xsrl = (unsigned) x >> k;

  int w  = sizeof(int) << 3;
  int mask = (int) -1 << (w - k);

  int m = 1 << (w - 1);
  mask &= !(x & m) - 1;
  return xsrl | mask;
}

int main()
{
  assert(srl(0x80000000, 0) == (0x80000000));
  return 0;
}
