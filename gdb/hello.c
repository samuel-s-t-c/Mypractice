#include <stdio.h>
#include <unistd.h>

int main()
{
  {
    int i = 80;
    while (i != 1) {
      --i;
    }
  }
  printf("Hello, World!\n");
  return 0;
}
