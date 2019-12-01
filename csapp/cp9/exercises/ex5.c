#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void unix_error(char *err)
{
  fprintf(stderr, "%s: %s\n", err, strerror(errno));
  _exit(0);
}

void mmapcopy(int fd, size_t size)
{
  char *bufp;

  bufp = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (bufp == MAP_FAILED)
    unix_error("mmap error");

  if (write(1, bufp, size) < 0)
    unix_error("write error");

  return;
}

int main(int argc, char **argv)
{
  struct stat stat;
  int fd;

  if (argc != 2) {
    printf("usage: %s <filename>\n", argv[0]);
    exit(0);
  }

  fd = open(argv[1], O_RDONLY, 0);
  if (fd < 0)
    unix_error("open error");

  fstat(fd, &stat);
  mmapcopy(fd, stat.st_size);
  exit(0);
}
