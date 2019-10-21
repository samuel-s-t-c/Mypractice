
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

int tsub_ok(int x, int y)
{
  int w = sizeof(int) << 3;
  int r = x - y;
  x >>= (w - 1);
  y >>= (w - 1);
  r >>= (w - 1);
  return (x != y) && (y == r);
}
