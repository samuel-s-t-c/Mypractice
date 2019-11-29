#include <signal.h>
#include <string.h>
#include <errno.h>

int main()
{
  psignal(3, strerror(errno));
  return 0;
}
