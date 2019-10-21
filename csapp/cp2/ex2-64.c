
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */
/* Assume w = 32; */

#include <assert.h>

int any_odd_one(unsigned x)
{
  return (0xaaaaaaaa & x) != 0;
}

int main()
{
  assert(any_odd_one(2) == 1);
  assert(any_odd_one(10) == 1);
  assert(any_odd_one(0) == 0);
  return 0;
}
