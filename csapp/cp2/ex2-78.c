
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>
#include <math.h>

/* Assuem 0 <= k < w - 1 */
int divide_power2(int x, int k)
{
  int ret = x >> k;
  int w = sizeof(int) << 3;
  ret += (x >> (w - 1)) && (x & ((1 << k) - 1));
  return ret;
}

int main()
{
  int x = 0x8000ffff;
  assert(divide_power2(x, 0) == x);
  assert(divide_power2(x, 1) == x / 2);
  assert(divide_power2(x, 31) == x / (int)pow(2, 31) );
}
