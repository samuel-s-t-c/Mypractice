#include <stdio.h>
void inplace_swap(int *lhs, int *rhs)
{
  *lhs = *lhs ^ *rhs;
  *rhs = *lhs ^ *rhs;
  *lhs = *lhs ^ *rhs;
}

void reverse_array(int *a, int cnt)
{
  for (int first = 0, last = cnt - 1; first < last; ++first, (void)--last)
    inplace_swap(&a[first], &a[last]);
}

int main()
{
  #define size 5
  int arr[size] = {1, 2, 3, 4, 5};
  for (int i = 0; i < size; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
  reverse_array(arr, size);
  for (int i = 0; i < size; ++i) {
    printf(" %d", arr[i]);
  }
  printf("\n");
  return 0;
}
