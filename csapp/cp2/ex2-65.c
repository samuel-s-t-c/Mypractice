
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */
//Assume w = 32;
#include <assert.h>

int odd_ones(unsigned x)
{
  x ^= x >> 16;
  x ^= x >> 8 ;
  x ^= x >> 4 ;
  x ^= x >> 2 ;
  x ^= x >> 1 ;
  return x & 1;
}
