#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void unix_error(char *err)
{
  fprintf(stderr, "%s: %s\n", err, strerror(errno));
  exit(0);
}

int Read(int fd, void *buf, size_t count)
{
  int ret = read(fd, buf, count);
  if (ret < 0) {
    unix_error("read error");
    exit(0);
  }
  return ret;
}

int Write(int fd, void *buf, size_t count)
{
  int ret = write(fd, buf, count);
  if (ret < 0) {
    unix_error("write error");
    exit(0);
  }
  return ret;
}

int main(void)
{
  char c[10];
  int ret;
  fprintf(stdout, "hi\n");
  while ((ret = Read(STDIN_FILENO, c, 10)) != 0) {
    fprintf(stdout, "\n%d: ", ret);
    fflush(stdout);
    Write(STDOUT_FILENO, c, 10);
  }
  return 0;
}
