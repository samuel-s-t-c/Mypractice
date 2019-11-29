#include "csapp.h"

int counter = 0;

void handler1(int sig)
{
  counter++;
  sleep(1);
  return;
}

int main()
{
  int i;

  Signal(SIGUSR2, handler1);

  if (Fork() == 0) {
    for (i = 0; i < 5; i++) {
      Kill(getppid(), SIGUSR2);
      printf("sent SIGUSR2 to parent\n");
    }
    exit(0);
  }

  Wait(NULL);
  printf("counter=%d\n", counter);
  exit(0);
}
