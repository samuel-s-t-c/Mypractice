#include "../../code/include/csapp.h"

#define MYMAXBUF (1<<4)

int main(int argc, char **argv)
{
  int n;
  rio_t rio;
  char buf[MYMAXBUF];
  char s[10];

  Rio_readinitb(&rio, STDIN_FILENO);
  while ((n = Rio_readlineb(&rio, buf, MYMAXBUF)) != 0) {
    fprintf(stderr, "\n%d: ", n);
    Rio_writen(STDOUT_FILENO, buf, n);
  }
}
