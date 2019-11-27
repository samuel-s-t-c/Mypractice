#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define N 2

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
  int status, i;
  pid_t pid[N], retpid;

  for (i = 0; i < N; i++)
    if ((pid[i] = fork()) == 0)
      exit(100+i);

  i = 0;
  pid_t cpid, ppid;
  while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
    cpid = getpid();
    ppid = getppid();
    if (WIFEXITED(status))
      printf("child %d terminated normally with exit status=%d (pid:%d ppid: %d)\n",
             retpid, WEXITSTATUS(status), cpid, ppid);
    else
      printf("child %d terminated abnormally\n", retpid);
  }

  if (errno != ECHILD)
    fprintf(stderr, "%s: %s\n", "waitpid error", strerror(errno));

  exit(0);
}
