
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */
//Assume w = 32;

#include <assert.h>

int int_size_is_32()
{
  int x = 1 << 15 << 15;
  int set_msb = x << 1;
  int beyond_msb = x << 2;
  return set_msb && !beyond_msb;
}

int main()
{
  assert(int_size_is_32());
}
