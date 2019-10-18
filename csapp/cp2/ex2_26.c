#include <string.h>
#include <stdio.h>

int strlonger(char *s, char *r)
{
  return strlen(s) > strlen(r);
}

int main()
{
  char s [2] = "1";
  char r [3] = "12";
  printf("%d\n", strlonger(s, r));
}
