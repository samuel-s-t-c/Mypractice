
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 * --------
 * Do rotating left shift.
 * Assume 0 <= n < w
 */

#include <assert.h>

unsigned rotate_left(unsigned x, int n)
{
  int w = sizeof(unsigned) * 8;
  return (x << n) | (x >> (w - n - 1) >> 1);
}

int main()
{
  assert(rotate_left(0x12345678, 0) == 0x12345678);
  assert(rotate_left(0x12345678, 4) == 0x23456781);
  return 0;
}
