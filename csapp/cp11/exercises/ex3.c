#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
  uint32_t addr;
  struct in_addr inaddr;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <dotted-decimal>", argv[0]);
    exit(0);
  }

  int rc = inet_pton(AF_INET, argv[1], &inaddr);
  if (rc == 0) {
    fprintf(stderr, "inet_pton error: invalid doutted-decimal address\n");
    exit(0);
  } else if (rc < 0) {
    fprintf(stderr, "inet_pton error: %s\n", strerror(errno));
    exit(0);
  }

  addr = ntohl(inaddr.s_addr);
  printf("0x%x\n", addr);

  return 0;
}
