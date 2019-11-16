void merge(long src1[], long src2[], long dest[], long n)
{
  long i1 = 0;
  long i2 = 0;
  long id = 0;
  while (i1 < n && i2 < n) {
    long v1 = src1[i1];
    long v2 = src1[i2];
    long cond = v1 < v2;
    dest[id++] = cond ? v1 : v2;
    i1 += cond;
    i2 += (1 - cond);
  }
  while (i1 < n)
    dest[id++] = src1[i1++];
  while (i2 < n)
    dest[id++] = src2[i2++];
}
