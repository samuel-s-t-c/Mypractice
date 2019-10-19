#include <stddef.h>
#include <stdlib.h>

void *simple_calloc(size_t ele_cnt, size_t ele_size)
{
  if (ele_size == 0 || ele_size ==0)
    return NULL;
  size_t buff_size = ele_size * ele_cnt;
  if (buff_size / ele_size == ele_cnt) {
    void *ptr = malloc(buff_size);
    return ptr;
  }
  return NULL;
}
