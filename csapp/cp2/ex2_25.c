#include <stdio.h>

float sum_elements(float a[], unsigned length)
{
  float result = 0;
  for (unsigned i = 0; i < length; ++i)
    result += a[i];
  return result;
}

int main()
{
  float a [1];
  printf("%f\n",sum_elements(a, 0));
}
