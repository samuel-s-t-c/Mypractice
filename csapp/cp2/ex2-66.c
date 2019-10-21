
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */
//Assume w = 32;

#include <assert.h>

int leftmost_one(unsigned x)
{
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}

int main()
{
  assert(leftmost_one(0xffffffff) == 0x80000000);
  return 0;
}
