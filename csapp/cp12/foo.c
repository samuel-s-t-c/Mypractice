#include <time.h>
#include <stdio.h>

int main()
{
  char *ret;
  time_t val_tm;
  struct tm time;
  time.tm_year = 0;
  val_tm = mktime(&time);
  ret = ctime(&val_tm);
  printf("%s\n", ret);
  time.tm_mon = 11;
  val_tm = mktime(&time);
  ctime(&val_tm);
  printf("%s\n", ret);
}
