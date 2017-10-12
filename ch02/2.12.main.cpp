#include "2.12.CLLogger.h"
#include "2.7.CLStatus.h"

CLStatus f()
{
  return CLStatus(-1, 4);
}

int main()
{
  CLStatus s = f();
  if (!s.IsSuccess())
  {
    CLLogger* pLogger = CLLogger::GetInstance();
    if (pLogger != 0)
      pLogger -> WriteLog("this is an error", s.m_clErrorCode);
  }
  return 0;
}
