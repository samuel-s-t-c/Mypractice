#include <stdio.h>
#include <math.h>

typedef unsigned float_bits;

float u2f(unsigned x)
{
  return *((float *) &x);
}

unsigned f2u(float x)
{
  return *((unsigned *)&x);
}

int is_float_equal(float_bits f1, float f2)
{
  return f2u(f2) == f1;
}

int is_nan(float_bits fb)
{
  /* unsigned sign = fb >> 31; */
  unsigned exp = (fb >> 23) & 0xff;
  unsigned fract = fb & 0x7fffff;
  return exp == 0xff && fract != 0;
}

int is_inf(float_bits fb)
{
  /* unsigned sign = fb >> 31; */
  unsigned exp = fb >> 23 & 0xff;
  unsigned fract = fb & 0x7fffff;
  return exp == 0xff && fract == 0;
}

int testfun(float_bits(*fun1)(float_bits), float(*fun2)(float))
{
  unsigned x = 0;
  do {
    float_bits fb = fun1(x);
    float ff = fun2(u2f(x));
    if (!is_float_equal(fb, ff)) {
      printf("%x error \n", x);
      printf("float_bits: %x\nfloat: %x\n", fb, f2u(ff));
      return 0;
    }
    x++;
  } while (x != 0);
  printf("Test OK\n");
  return 1;
}

// ex2-92
float_bits float_negate(float_bits f)
{
  if (is_nan(f)) return f;
  return f ^ 0x80000000;
}

float float_negate_f(float f)
{
  if (is_nan(f2u(f)))
    return f;
  return -f;
}

// ex2-93
float_bits float_absval(float_bits f)
{
  if (is_nan(f))
    return f;
  else return f & 0x7fffffff;
}

float float_absval_f(float f)
{
  if (is_nan(f2u(f)))
    return f;
  else if (f == 0)
    return 0;
  else return f < 0 ? -f : f;
}

// ex2-94
float_bits float_twice(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xff;
  unsigned fract = f & 0x7fffff;

  if (exp == 0)
    return sign << 31 | fract << 1;
  else if (exp < 0xfe)
    return sign << 31 | (exp + 1) << 23 | fract;
  else if (exp == 254)
    return sign << 31 | 0xff << 23;
  return f;
}

float float_twice_f(float f)
{
  if (is_nan(f2u(f))) return f;
  return 2 * f;
}

// ex2-95
float_bits float_half(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xff;
  unsigned fract = f & 0x7fffff;

  if (exp == 0)
    return sign << 31 | ((fract >> 1) + ((fract & 1) && ((fract >> 1) & 1)));
  if (exp == 1)
    return sign << 31 | (((1 << 22) | (fract >> 1)) +((fract & 1) && ((fract >> 1) & 1)));
  if (exp != 0xff)
    return sign << 31 | (exp - 1) << 23 | fract ;
  return f;
}

float float_half_f(float f)
{
  if (is_nan(f2u(f)))
    return f;
  return (float)0.5 * f;
}

// ex2-96
int float_f2i(float_bits f)
{
  unsigned sign = f >> 31;
  int exp = f >> 23 & 0xff;
  int fract = (f & 0x7fffff) | 1 << 23;

  exp -= 127;
  if (exp < 0)
    return 0;
  else if (exp < 23)
    fract >>= (23 - exp);
  else if (exp < 31)
    fract <<= (exp - 23);
  else return 0x80000000;
  return sign ? -fract : fract;
}


// ex2-97
float_bits float_i2f(int i)
{
  if (i == 0)
    return 0;
  unsigned absval = i > 0 ? i : -i;
  unsigned sign = 0x80000000 & i;
  int leftmost1 = (sizeof(int) << 3) - 1;
  while (leftmost1 >= 0) {
    if ((absval >> leftmost1) & 1)
      break;
    --leftmost1;
  }

  unsigned fract;
  unsigned exp = 127 + leftmost1;

  if (leftmost1 <= 23) {
    fract = absval << (23 - leftmost1);
  } else {
    fract = absval >> (leftmost1 - 23);
    unsigned cutoff = absval & (1 << (leftmost1 - 23)) - 1;
    if (cutoff > (1 << (leftmost1 - 24)))
      ++fract;
    else if (cutoff == (1 << (leftmost1 - 24)) && fract & 1)
      ++ fract;
    if (fract == (1 << 24)) ++exp;
  }
  /* printf("%x %x %x %d %x\n", sign, exp, fract & 0x7fffff, leftmost1, absval); */
  return sign | exp << 23 | (fract & 0x7fffff);
}

int main()
{
  int x = 0;
  do {
    float m = u2f(float_i2f(x));
    float n = (float)(x);
    if (m != n) {
      printf("error in %x\nmyconversion: %f\n%f\n", x, m, n);
      return 1;
    }
    x++;
  }while(x!=0);
  printf("Success!\n");
  return 0;
}
