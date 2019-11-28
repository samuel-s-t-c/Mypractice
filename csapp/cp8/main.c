#include <stdio.h>
#include <signal.h>
#include "csapp.h"

volatile long counter = 2;

void handler1(int sig)
{
  sigset_t mask, prev_mask;
  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);
  Sio_putl(--counter);
  Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
  return;
}

int main()
{
  sigset_t mask, prev_mask;
  printf("main:%ld\n", counter);
  fflush(stdout);

  signal(SIGUSR1, handler1);
  Kill(0, SIGUSR1);

  Sigfillset(&mask);
  Sigprocmask(SIG_BLOCK, &mask, &prev_mask);  /* Block sigs */
  printf("\nmain:%ld\n", ++counter);
  Sigprocmask(SIG_SETMASK, &prev_mask, NULL); /* Restore sigs */
  exit(0);
}
