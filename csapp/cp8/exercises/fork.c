#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

pid_t Fork(void)
{
  pid_t pid = fork();
  if (pid < 0) {
    fprintf(stderr, "%s: %s\n", "Fork error", strerror(errno));
  }
  return pid;
}

int main()
{
  pid_t pid;
  int x = 1;

  pid = Fork();
  if (pid == 0) {
    printf("child: x=%d\n", ++x);
    exit(0);
  }

  printf("parent: x=%d\n", --x);
  exit(0);
}
