
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
  int w = sizeof(unsigned) << 3;
  return signed_high_prod(x, y)
         + ((int)x >> (w - 1)) & y
         + ((int)y >> (w - 1)) & x;
}
