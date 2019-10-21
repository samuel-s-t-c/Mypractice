/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 *
 * Mask with least signficant n bits set to 1
 * Assume 1 <= n <= w
 */

#include <assert.h>

int lower_one_mask(int n)
{
  if (n == 0)
    return 0;
  return (2 << (n - 1)) - 1;
}

int main()
{
  assert(lower_one_mask(0) == 0);
  assert(lower_one_mask(32) == (int)0xffffffff);
  return 0;
}
