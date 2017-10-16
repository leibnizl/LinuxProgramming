#pragma once

#include "2.7.CLStatus.h"

class CLLogger
{
 public:
  static CLLogger* GetInstance();
  static CLStatus WriteLogMsg(const char *pstrMsg, long lErrorCode);
  CLStatus WriteLog(const char* pstrMsg, long lErrorCode);
  CLStatus Flush();

 private:
  CLLogger(const CLLogger&);
  CLLogger& operator=(const CLLogger&);

  CLLogger();
  ~CLLogger();

  int m_Fd;
  static CLLogger *m_pLog;

 private:
  char *m_pLogBuffer;
  unsigned int m_nUsedBytesForBuffer;
};
