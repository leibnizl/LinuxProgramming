#include "2.14.CLLogger.h"
#include "2.7.CLStatus.h"

#include <sys/time.h>
#include <stdio.h>


int main()
{
  const int n = 1000000;

  struct timeval tv;
  gettimeofday(&tv, 0);

  for (int i = 0; i < n; i++)
  {
    CLLogger:: WriteLogMsg("nihao", 0);
  }

  CLLogger* pLog = CLLogger:: GetInstance();
  pLog -> Flush();

  struct timeval tv1;
  gettimeofday(&tv1, 0);

  long t = 1000000 * (tv1.tv_sec - tv.tv_sec) + (tv1.tv_usec - tv.tv_usec);
  printf("%ld\n", t);
  return 0;
}
