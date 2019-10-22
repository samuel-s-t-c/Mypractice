
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <stdlib.h>
#include <stdio.h>

int main()
{
  int x = random(), y = random();
  unsigned ux = (unsigned) x, uy = (unsigned) y;

  /* x = (int)0x80000000; */
  printf("(x < y) == (-x > -y) : %d\n", (x < y) == (-x > -y));
  return 0;
}
