#include "2.13.CLLogger.h"

CLStatus f()
{
  return CLStatus(-1, 4);
}

int main()
{
  CLStatus s = f();
  if (!s.IsSuccess())
  {
    CLLogger:: WriteLogMsg("this is an error", s.m_clErrorCode);
  } 
  return 0;
}
