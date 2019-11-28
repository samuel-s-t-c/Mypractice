#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs)
{
  unsigned int rest = sleep(secs);
  printf("Slept for %d of %d secs.\n",
         secs-rest, secs);
  return rest;
}
