#include <stdio.h>
#include <stdlib.h>

int main()
{
  int size, *array;
  printf("array size is ");
  scanf("%d", &size);
  array = (int *) malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
    scanf("%d", &array[i]);
  for (int i = 0; i < size; i++)
    printf("%d: %d\n", i, array[i]);
  free(array);
  return 0;
}
