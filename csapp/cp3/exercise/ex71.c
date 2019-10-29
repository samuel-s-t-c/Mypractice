#include <stdio.h>
#include <assert.h>

#define BUFFER_SIZE 12

void good_echo(void)
{
  char buf[BUFFER_SIZE];
  while (fgets(buf, BUFFER_SIZE, stdin) != NULL) {
    printf("%s", buf);
  }
}

int main(int argc, char *argv[])
{
  good_echo();
  return 0;
}
