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
  unsigned ui = 0x86;
  printf("0x");
  show_bytes((byte_pointer)&ui, sizeof(unsigned int));
  ui = ui << 24;
  printf("0x");
  show_bytes((byte_pointer)&ui, sizeof(unsigned int));
  int i = (int)(ui) >> 24;
  printf("0x");
  show_bytes((byte_pointer)&i, sizeof(unsigned int));
}
