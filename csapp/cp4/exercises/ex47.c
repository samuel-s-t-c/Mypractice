/* #include <stdio.h> */
#define arrsize 7
/* void print_a(long *arr, long count) */
/* { */
/*   for (long *p = arr; p != arr + count; p++) { */
/*     printf("%ld ", *p); */
/*   } */
/*   printf("\n"); */
/* } */
void bubble_p(long *data, long count)
{
  /* printf("initial array: "); */
  /* print_a(data, count); */
  long *i, *last;
  /* int cnt = 0; */
  for (last = data + count - 1 ; last != data ; last--) {
    for (i = data; i < last; i++) {
      if (*(i + 1) < *i) {
        long t = *(i+1);
        *(i+1) = *i;
        *i = t;
      }
      /* cnt++; */
      /* printf("%-2d : ",cnt); */
      /* print_a(data, count); */
    }
  }
}

int main()
{
  long arr[arrsize] = {8, 9, 4, 2, 3, 5, 7};
  bubble_p(arr, arrsize);
}
