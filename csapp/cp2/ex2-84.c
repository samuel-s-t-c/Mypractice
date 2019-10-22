int main()
{
  unsigned ux, uy, sx, sy;
  ux = uy = sx = sy = 0;
  int ret =(!(ux << 1) && !(uy << 1)) ||
           (sx && !sy) ||
           (!sx && !sy && ux >= uy) ||
           (sx && sy && ux <= uy);
}
