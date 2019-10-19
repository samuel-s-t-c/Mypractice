#include <stdint.h>

int tmult32_ok(int32_t x, int32_t y)
{
  int64_t sum = (int64_t)x * y;
  return sum == (int32_t)sum;
}
