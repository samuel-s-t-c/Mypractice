void func(char *di)
{
  char exp[] = "1234";
  char rsp[6] = "flyers";
  int ax = 0;
  while (ax != 6) {
    *(rsp + ax + 16) = *(exp + (0xf & di[ax]));
    ++ax;
  }
  *(rsp + 22) = 0;
}
{
  9fe567
}
maduiersnfotvbylSo you think you can stop the bomb with ctrl-c, do you?
01234567890123456789012345678901234567890123456789012345678901234567890

