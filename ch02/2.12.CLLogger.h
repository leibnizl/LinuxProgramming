#include "2.7.CLStatus.h"

class CLLogger
{
 public:
  static CLLogger* GetInstance();
  CLStatus WriteLog(const char* pstrMsg, long lErrorCode);

 private:
  CLLogger(const CLLogger&);
  CLLogger& operator=(const CLLogger&);

  CLLogger();
  ~CLLogger();

  int m_Fd;
  static CLLogger *m_pLog;
};
