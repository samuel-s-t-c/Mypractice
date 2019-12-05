#include "../../code/include/csapp.h"

int main(int argc, char **argv)
{
  struct stat stat;
  char *type, *readok;
  if (argc < 2)
    return -1;
  Stat(argv[1], &stat);
  if (argc == 3) {
    int fd = Open(argv[2], O_TRUNC|O_CREAT|O_WRONLY, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    Dup2(fd, 1);
  }

  if (S_ISREG(stat.st_mode))
    type = "regular";
  else if (S_ISDIR(stat.st_mode))
    type = "dir";
  else
    type = "other";
  if ((stat.st_mode & S_IRUSR))
    readok = "yes";
  else
    readok = "no";

  printf("type: %s, read: %s\n", type, readok);

  return 0;
}
