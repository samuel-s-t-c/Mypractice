double funct3(int *ap, double b, long c, float *dp)
{
  if (b > *ap) {
    return c * (*dp);
  } else {
    return c + 2 * (*dp);
  }
}
