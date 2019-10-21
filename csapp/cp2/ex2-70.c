
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 * ----------
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */

#include <assert.h>

int fits_bits(int x, int n)
{
  if (n > 0) {
    x >>= (n - 1);
    return !x || !(~x);
  }
  return 0;
}

int main()
{
  assert(fits_bits(0b010, 2) == 0);
  assert(fits_bits(0b110, 2) == 0);
}
