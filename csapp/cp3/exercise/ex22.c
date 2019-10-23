#include <stdio.h>

void int32n()
{
  int n = 1;
  int result = 1;
  int previous = 1;
  do {
    printf("%d\t%-10d\t%-10c\n", n, result, 'y');
    previous = result;
    result *= ++n;
  } while (result/n == previous);
  printf("%d\t%-10d\t%-10c\n", n, result, 'n');
}

void long64n()
{
  long n = 1;
  long result = 1;
  long previous = 1;
  do {
    printf("%ld\t%-20ld\t%-10c\n", n, result, 'y');
    previous = result;
    result *= ++n;
  } while (result/n == previous);
  printf("%ld\t%-20ld\t%-10c\n", n, result, 'n');
}
int main()
{
  long64n();
  return 0;
}
