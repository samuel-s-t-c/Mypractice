/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

int int_shifts_are_arithmetic()
{
  int x = -1;
  return (x == (x >> 1));
}

int main()
{
  assert(int_shifts_are_arithmetic());
  return 0;
}
