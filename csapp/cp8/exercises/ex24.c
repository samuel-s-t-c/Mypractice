#include "csapp.h"
#define N 2

int main()
{
  int status, i;
  pid_t pid;

  for (i = 0; i < N; i++)
    if ((pid = Fork()) == 0) {
      char *cptr = NULL;
      *cptr = 'd';
    }

  while ((pid = waitpid(-1, &status, 0)) > 0) {
    if (WIFEXITED(status))
      printf("child %d terminated normally with exit status=%d\n",
             pid, WEXITSTATUS(status));
    else if (WIFSIGNALED(status)) {
      fprintf(stderr, "child %d terminated by signal %d",
              pid, WTERMSIG(status));
      psignal(WTERMSIG(status), " ");
    }
    else
      printf("child %d terminated abnornally\n", pid);
  }

  if (errno != ECHILD)
    unix_error("waitpid error");

  exit(0);
}
