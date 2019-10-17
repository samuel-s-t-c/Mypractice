#include <stdio.h>

unsigned long low_byte_of(unsigned long input)
{
  return input & 0xff;
}

unsigned long not_e_low(unsigned long input)
{
  return (~0) & (~0xff) ^ input;
}


int main()
{
  unsigned long i = 0x87654321;
  printf("0x%.16lx\n",i);
  printf("0x%.16lx\n",low_byte_of(i));
  printf("0x%.16lx\n",not_e_low(i));
  printf("0x%.16lx\n",i | 0xff);
  return 0;
}
