void phase(char *di)
{
  char *sp = "1";
  char *r13, *r14, *bp;
  int ax;
  int si[6];
  int r12, bx, cx, dx;
  r14 = r13 = sp;
  r12 = 0;

 x114:
  bp = sp;
 /*  ax = si[0]; */
 /*  --ax; */
 /*  if (ax != 5) goto x128; */
 /*  return; */

 /* x128: */
 /*  ++r12; */
 /*  if (r12 == 6) goto x153; */
 /*  bx = r12; */

 /* x135: */
 /*  ax = *(sp + 4 * bx); */
 /*  if (*bp != ax) goto x145; */
 /*  return; */

 /* x145: */
 /*  ++bx; */
 /*  if (bx <= 5) goto x135; */
 /*  r13 += 4; */
 /*  goto x114; */

  {
    char *ax, *dx;
    int si;
  x153:
    si = sp + 24;
    ax = r14;
    cx = 7;

 x160:
    dx = cx;
    dx -= *ax;
    *ax = dx;
    ax += 4;
    if (ax != si) goto x160;
    si = 0;
    goto x197;

  x176:
    dx = *(dx + 8);
    ++ax;
    if (ax != cx) goto x176;
    goto x188;

  x183:
    dx = 0x6032d0;

  x188:
    *(sp + 2 * si + 20) = dx;
    si += 4;
    if (si == 24) goto x1ab;

  x197:
    cx = *(sp + si);
    if (cx <= 1) goto x183;
    ax = 1;
    dx = 0x6032d0;
    goto x176;

  x1ab:
    bx = *(sp + 32);
    ax = *(sp + 40);
    si = *(sp + 80);
    cx = bx;

  x1bd:
    dx = *ax;
    *(cx + 8) = dx;
    ax += 8;
    if (ax == si) goto x1d2;
    cx = dx;
    goto x1bd;

  x1d2:
    *(dx + 8) = 0;
    bp = 5;

  x1df:
    ax = *(bx + 8);
    ax = *ax;
    if (*bx >= ax) goto x1ee;
    return;

  x1ee:
    bx = *(bx + 8);
    bp --;
    if (bp != 0) goto x1df;
    return;
  }
}
