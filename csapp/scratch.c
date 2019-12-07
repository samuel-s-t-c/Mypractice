#include "code/include/csapp.h"

int main(int argc, char **argv)
{
  char buf[MAXBUF] = "Hello, world! My name is hp.";
  char buf1[MAXBUF];
  FILE *f = Fopen(argv[1], "w+");
  FILE *r = Fopen(argv[1], "r+");
  fprintf(f, "%s", buf);
  fflush(f);
  fseek(f, 0, SEEK_SET);
  fscanf(f, "%28c", buf1);
  fprintf(stdout, "1: %s\n", buf1);

  fseek(f, 0, SEEK_SET);
  fscanf(f, "%s", buf1);
  fprintf(f, "%s", buf1);
  fscanf(r, "%40c", buf1);
  fprintf(stdout, "2: %s\n", buf1);

  return 0;
}
