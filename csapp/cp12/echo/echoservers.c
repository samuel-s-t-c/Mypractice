#include "../csapp.h"
#include "../sbuf.h"

sbuf_t buf;

int main(int argc, char **argv)
{
  int listenfd;

  if (argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }

  sbuf_init(&buf, -1);

  listenfd = Open_listenfd(argv[1]);
  while (1) {
  }
}
