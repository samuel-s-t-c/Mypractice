#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

unsigned int snooze(unsigned int secs);

void hanlder (int sig)
{
  write(STDOUT_FILENO, "\nCaught SIGINT!\n", 16);
  return;
}

int main(int argc, char **argv)
{
  if (argc != 2) {
    fprintf(stderr, "usage : %s <secs>\n", argv[0]);
    exit(0);
  }

  if (signal(SIGINT, hanlder) == SIG_ERR)
    fprintf(stderr, "signal error\n");
  snooze(atoi(argv[1]));
  exit(0);
}
