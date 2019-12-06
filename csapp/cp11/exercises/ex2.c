#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXBUF 17

int main(int argc, char **argv)
{
  uint32_t addr;
  struct in_addr inaddr;
  char buf[MAXBUF];

  if (argc != 2) {
    fprintf(stderr, "usage: %s <hexadecimal>", argv[0]);
    exit(0);
  }

  sscanf(argv[1], "%x", &addr);

  inaddr.s_addr = htonl(addr);

  if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF)) {
    fprintf(stderr, "inet_ntop error: %s\n", strerror(errno));
    exit(0);
  }
    printf("%s\n", buf);

  return 0;
}
