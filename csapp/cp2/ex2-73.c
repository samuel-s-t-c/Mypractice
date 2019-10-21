
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 * ----------
 * Addition that saturates to TMin or TMax
 */

#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
  int sum = x + y;
  int sig_mask = INT_MIN;

  int pos_ovf = !(x & sig_mask) && !(x & sig_mask) && (sum & sig_mask);
  int neg_ovf = (x & sig_mask) && (x & sig_mask) && !(sum & sig_mask);

  (pos_ovf && (sum = INT_MAX)) || (neg_ovf && (sum = INT_MIN));

  return sum;
}
