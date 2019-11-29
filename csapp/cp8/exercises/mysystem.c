#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* extern char **environ; */

int mysystem(char *command)
{
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "Fork error: %s\n", strerror(errno));
    exit(0);
  }
  if (pid == 0) {
    char *argv[] = {"sh", "-c", command, NULL};
    if (execve("/bin/sh", argv, (char **)0) < 0) {
      fprintf(stderr, "Execl error: %s\n", strerror(errno));
      exit(0);
    }
  }
  int status;
  if ((waitpid(pid, &status, 0)) < 0) {
    fprintf(stderr, "waitpid error: %s\n", strerror(errno));
    exit(0);
  } else {
    if (WIFEXITED(status))
      return WEXITSTATUS(status);
    if (WIFSIGNALED(status))
      return WTERMSIG(status);
  }
}

int main()
{
  int code;

  code = mysystem("./text1");
  printf("testing normal exit: %d\n", code);

  code = mysystem("./text2");
  printf("testing abnormal exit: %d\n", code);
}
