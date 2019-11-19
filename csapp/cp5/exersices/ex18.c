#include <stdio.h>
#include <string.h>
#include <assert.h>

double poly1(double a[], double x, long degree)
{
  long i;
  double result = a[0];
  double xpwr = x;
  for (i = 1; i <= degree; i++) {
    result += a[i] * xpwr;
    xpwr = x * xpwr;
  }
  return result;
}

double poly2(double a[], double x, long degree)
{
  long i;
  double result = a[degree];
  for (i = degree-1; i >= 0; i--) {
    result = a[i] + x * result;
  }
  return result;
}

double poly3(double a[], double x, long degree)
{
  long i;
  double result = a[degree];
  double lastone = a[degree];
  for (i = degree-1; i >= 0; i--) {
    result = a[i] + x * lastone;
    lastone = result;
  }
  return result;
}

int main()
{
  double a[1000] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2};
  double x = 6;
  long degree = 300;
  double r1 = poly1(a, x, degree);
  double r2 = poly2(a, x, degree);
  double r3 = poly3(a, x, degree);

  printf("%f, %f, %f\n", r1, r2, r3);

  /* assert(r1 == r2 && r2 == r3); */
}
