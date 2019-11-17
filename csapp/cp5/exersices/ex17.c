#include <stdlib.h>
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

int main()
{
}
