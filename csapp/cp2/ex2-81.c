#include <assert.h>

int main()
{
  int x = -1;
  int k = 3;
  int j = 4;
  assert((x << k) == (int)0xfffffff8);
  assert(((~(x << k) )<< j) == (int)0x00000070);
}
