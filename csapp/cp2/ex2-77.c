
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 * ----------
 * Only valid operations are +, - and <<.
 */

#include <assert.h>

int main()
{
  int x = 2;
  assert( x * 17 == ((x << 4) + x)); // K = 17
  assert( x * -7 == ((x << 31) + (x << 31) - (x << 3) + x)); // K = -7
  assert( x * 60 == ((x << 6) - (x << 2))); // K = 60
  assert( x * -112 == ((x << 31) + (x << 31) - (x << 7) + (x << 4))); // K = -112
}
