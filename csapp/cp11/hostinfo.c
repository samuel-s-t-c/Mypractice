#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE (1<<10)

int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "usage: %s <domain name> [service]\n", argv[0]);
    exit(0);
  }

  struct addrinfo hints, *rs, *p;
  char buf[MAXLINE], buf2[MAXLINE];
  char *buf1 = buf2;
  int rc, flags, buf1len = MAXLINE;
  char *argv1 = argv[1], *argv2 = argv[2];
  if (argc == 2) {
    argv2 = NULL;
    buf1 = NULL;
    buf1len = 0;
  }

  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  if ((rc = getaddrinfo(argv1, argv2, &hints, &rs)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
    exit(1);
  }

  flags = NI_NUMERICHOST;
  for (p = rs; p; p = p->ai_next) {
    getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, buf1, buf1len, flags);
    if (buf1 != NULL)
      printf("%s:%s\n", buf, buf1);
    else
      printf("%s\n", buf);
  }

  freeaddrinfo(rs);
  return 0;
}
