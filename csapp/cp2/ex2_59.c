#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
  for (size_t i = 0; i < len; ++i)
    printf(" %.2x", start[i]);
  printf("\n");
}

void show_int(int x)
{
  show_bytes((byte_pointer) &x, sizeof(int));
}

int main()
{
  int x = 0x89abcdef, y = 0x765432ef;
  int c = (~0xff & y)|(x & 0xff);
  show_int(c);
  return 0;
}
