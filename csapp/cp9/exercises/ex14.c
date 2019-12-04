#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

void unix_error(char *err)
{
  fprintf(stderr, "%s: %s\n", err, strerror(errno));
  exit(0);
}

int main(int argc, char **argv)
{
  struct stat stat;
  if (argc != 2) {
    printf("usage: %s <File>\n", argv[0]);
    exit(0);
  }

  int fd;
  if ((fd = open(argv[1], O_RDWR, 0)) < 0)
    unix_error("open error");

  fstat(fd, &stat);

  char *bufp;
  size_t size = stat.st_size;

  bufp = mmap(NULL, size, PROT_WRITE|PROT_READ, MAP_PRIVATE, fd, 0);
  if (bufp == MAP_FAILED)
    unix_error("mmap error");

  if (close(fd) < 0)
    unix_error("close error");

  if ((write(1, bufp, size)) < 0)
    unix_error("write error");

  bufp[0] = 'J';

  if ((write(1, bufp, size)) < 0)
    unix_error("write error");

  if ((munmap(bufp, size)) < 0)
    unix_error("munmap error");

  exit(0);
}
