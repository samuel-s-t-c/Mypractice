#include <stdio.h>
#include "csapp.h"

#define SIZE 20
sigjmp_buf buf;
void handler(int sig)
{
  siglongjmp(buf, 1);
}

char *tfgets(char *s, int size, FILE *stream)
{
  Signal(SIGALRM, handler);
  if (!sigsetjmp(buf, 1)) {
    alarm(5);
    s = fgets(s, size, stream);
  } else
    s = NULL;
  return s;
}

int main()
{
  char s[SIZE], *ret;
  ret = tfgets(s, SIZE, stdin);
  if ((void *)ret == NULL)
    printf("no input\n");
  else
    printf("input: %s", ret);
  return 0;
}
