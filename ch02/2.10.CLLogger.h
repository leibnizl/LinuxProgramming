#include "2.7.CLStatus.h"

class CLLogger
{
 public:
  CLLogger();
  virtual ~CLLogger();

  CLStatus WriteLog(const char* pstrMsg, long lErrorCode);

 private:
  CLLogger(const CLLogger&);
  CLLogger& operator=(const CLLogger&);

 private:
  int m_Fd;
};
