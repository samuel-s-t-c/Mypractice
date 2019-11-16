void psum1(float a[], float p[], long n)
{
  long i;
  float val, last_val;
  last_val = p[0] = a[0];
  for (i = 1; i < n; i++) {
    val = last_val + a[i];
    p[i] = val;
    last_val = val;
  }
}
