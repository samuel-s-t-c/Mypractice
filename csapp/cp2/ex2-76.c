
/* Assumptions:
 * Integers are represented in two's-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type 'int' is w bits long.
 */

#include <stdlib.h>
#include <string.h>

void *myCalloc(size_t nmenb, size_t size)
{
  if (nmenb == 0 || size == 0)
    return NULL;
  size_t buff_size = nmenb * size;
  if (buff_size / nmenb == size) {
    void *first = malloc(buff_size);
    if (first != NULL)
      memset(first, 0, buff_size);
    return first;
  }
  return NULL;
}
