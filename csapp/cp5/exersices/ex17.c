#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void *memset_basic(void *s, int c, size_t n)
{
  size_t cnt = 0;
  unsigned char *schar = s;
  while (cnt < n) {
    *schar++ = (unsigned char) c;
    cnt++;
  }
  return s;
}

void *mymemset(void *s, int c, size_t n)
{
  size_t cnt = 0;
  unsigned char *dest_c = s;
  unsigned long l_char;
  unsigned char *ptr_l_char = (unsigned char *)&l_char;
  unsigned char size_uc = sizeof(unsigned char);
  unsigned char size_ul = sizeof(unsigned long);

  for (size_t i = 0; i < size_ul/size_uc; i++) {
    *ptr_l_char++ = (unsigned char)c;
  }

  unsigned char addr_front = (unsigned char)s % size_ul;
  while (cnt < addr_front && cnt < n) {
    *dest_c++ = (unsigned char)c;
    cnt ++;
  }

  unsigned long *dest_l = (void *)dest_c;
  size_t rest = (n - cnt)/size_ul;
  size_t tail = (n - cnt)%size_ul;
  for(size_t i = 0; i < rest; i++)  {
    *dest_l++ = l_char;
  }

  dest_c = (unsigned char*)dest_l;
  for(size_t i = 0; i < tail; i++)  {
    *dest_c++ = (unsigned char)c;
  }

  return s;
}

int main(int argc, char **argv)
{
  size_t cnt;
  if (argc != 1) {
    char *ptr = argv[1];
    while (*ptr != '\0') {
      if (*ptr < 48 || *ptr > 57)
        break;
    }
    cnt = atoi(argv[1]);
  }
  else
    cnt = 65337;
  size_t size = sizeof(char) * cnt;

  void *basic_arry = malloc(size);
  void *my_arry = malloc(size);

  int basic_c = 0xff;
  int my_c = 0xff;

  memset_basic(basic_arry, basic_c, size);
  mymemset(my_arry, my_c, size);

  assert(memcmp(basic_arry, my_arry, size) == 0);

  free(basic_arry);
  free(my_arry);
}
