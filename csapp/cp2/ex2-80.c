
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

int threefourths(int x)
{
  int w = sizeof(int) << 3;
  int ret = (x >> 2) + (x >> 1);
  int b0 = x & 1;
  int b1 = (x >> 1) & 1;

  ret += (b0 & b1);
  ret += (x >> (w - 1)) && (b0 || b1);
  return ret;
}
