void cond(long a, long *p)
{
  if (p == 0)
    goto Done;
  if (*p >= a)
    goto Done;
  *p = a;
 Done:
  return;
}
