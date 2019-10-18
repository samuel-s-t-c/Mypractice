#include <stdio.h>

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
  for (size_t i = len; i > 0; --i)
    printf(" %.2x", start[i-1]);
  printf("\n");
}

void show_int(int x)
{
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
  show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_byte(int val)
{
  int ival = val, *pval = &ival;
  float fval = (float) ival;
  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}
int main()
{
  int a = -2;
  int b = 3;
  printf("%d\n", a % b );
  printf("%d\n", (a % b + b) % b);
  /* char c = 0xff; */
  /* c += 0x81; */
  /* show_bytes((byte_pointer)&c, sizeof(unsigned char)); */
  return 0;
}
