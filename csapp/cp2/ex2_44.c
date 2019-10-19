#include <stdio.h>
#include <stdint.h>

int main()
{
  unsigned val = 0x80000000;
  int32_t x = val;
  printf("when x = %d, (x > 0) || (x - 1 < 0) : %s\n" ,
         x,((x > 0) || (x - 1 < 0))?"true":"false");
  x = 7;
  printf("when x = %d, (x & 7) != 7 || (x << 29 < 0) : %s\n" ,
         x, ((x & 7) != 7 || (x << 29 < 0))?"true":"false");
  x = 49152;
  printf("when x = %d, (x * x) >= 0 : %s\n",
         x, (x * x) >= 0 ? "true" : "false");
  val = 0x7fffffff;
  x = val;
  printf("when x = %d, x < 0 || -x <= 0 : %s\n",
         x, (x < 0 || -x <= 0) ? "true" : "false");
  val = 0x80000000;
  x = val;
  printf("when x = %d, x > 0 || -x >= 0 : %s\n",
         x, (x > 0 || -x >= 0) ? "true" : "false");
  val = 0x00000002;
  x = val;
  val = 0xffffffff;
  int y = val;
  unsigned ux = x, uy = y;
  printf("when x = %d, y = %d, ux = %u, uy = %u\n, x + y == ux + uy : %s\n",
         x, y, ux, uy ,(x + y == ux + uy) ? "true" : "false");
  printf("when x = %d, y = %d, ux = 0x%x, uy = 0x%x\n, x * ~y + uy * ux == -x : %s\n",
         x, y, ux, uy ,(x * ~y + uy * ux == -x) ? "true" : "false");
}
