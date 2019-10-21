/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <assert.h>

int main()
{
  int x = 0xffffffff;
  assert((!~x) == 1);// !~x
  x = 0;
  assert((!x) == 1);// !x
  x = 0xffff;
  assert((!~(x | ~0xff)) == 1);// !~(x | ~0xff)
  x = 0x00fff0ff;
  assert(!(x&(0xff << ((sizeof(int)-1) << 3))));// !(x&(0xff << ((sizeof(int)-1)
  return 0;
}
