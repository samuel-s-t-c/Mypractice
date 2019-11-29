#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{
  if ((execve("/bin/ls", argv, envp)) == -1)
    fprintf(stderr, "execve error: %s\n", strerror(errno));
  exit(-1);
}
