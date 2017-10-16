#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "2.14.CLLogger.h"

#define LOG_FILE_NAME "2.14.CLLogger.txt"
#define MAX_SIZE 265
#define BUFFER_SIZE_LOG_FILE 2048

CLLogger:: CLLogger()
{
  m_Fd = open(LOG_FILE_NAME, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
  m_pLogBuffer = new char[BUFFER_SIZE_LOG_FILE];
  m_nUsedBytesForBuffer = 0;
}

CLLogger:: ~CLLogger()
{
  if(m_Fd != -1)
    close(m_Fd);
}

CLStatus CLLogger:: WriteLog(const char *pstrMsg, long lErrorCode)
{
  if (pstrMsg == 0)
    return CLStatus(-1, 0);
  if (strlen(pstrMsg) == 0)
    return CLStatus(-1, 0);

  unsigned int nleftroom = BUFFER_SIZE_LOG_FILE - m_nUsedBytesForBuffer;
  unsigned int len_strmsg = strlen(pstrMsg);

  char buf[MAX_SIZE];
  snprintf(buf, MAX_SIZE, " Error code: %ld\r\n", lErrorCode);

  unsigned int len_code = strlen(buf);
  
  unsigned int total_len = len_code + len_strmsg;

  // msg length exceeds the length of max buffer size,so firstly, Flush buffer; secondly, write msg into file directly
  if (total_len > BUFFER_SIZE_LOG_FILE)
  {
    CLStatus s = Flush();
    if (!s.IsSuccess())
      return CLStatus(-1, 0);

    if (m_Fd == -1)
      return CLStatus(-1, 0);
    ssize_t r = write(m_Fd, pstrMsg, len_strmsg);
    if (r == -1)
      return CLStatus(-1, 0);
    r = write(m_Fd, buf, len_code);
    if (r == -1)
      return CLStatus(-1, errno);

    return CLStatus(0, 0);
  }
  // msg length doesn't exceed the length of max buffer size, but the buffer contain something else, so the buffer cannot hold
  // the msg, so, firstly, Flush buffer; secondly, save msg to buffer;
  if (total_len > nleftroom)
  {
    CLStatus s = Flush();
    if (!s.IsSuccess())
      return CLStatus(-1, 0);
    //    return s;
  }

  memcpy(m_pLogBuffer + m_nUsedBytesForBuffer, pstrMsg, len_strmsg);
  m_nUsedBytesForBuffer += len_strmsg;
  memcpy(m_pLogBuffer + m_nUsedBytesForBuffer, buf, len_code);
  m_nUsedBytesForBuffer += len_code;

  return CLStatus(0, 0);
}


CLLogger* CLLogger:: m_pLog = 0;

CLLogger* CLLogger:: GetInstance()
{
  if (m_pLog == 0)
    m_pLog = new CLLogger;
  return m_pLog;
}


CLStatus CLLogger:: WriteLogMsg(const char* pstrMsg, long lErrorCode)
{
  CLLogger* pLog = CLLogger:: GetInstance();
  if (pLog == 0)
    return CLStatus(-1, 0);
  CLStatus s = pLog -> WriteLog(pstrMsg, lErrorCode);
  if (s.IsSuccess())
    return CLStatus(0, 0);
  return CLStatus(-1, 0);
}

CLStatus CLLogger:: Flush()
{
  if (m_Fd == -1)
    return CLStatus(-1, 0);
  if (m_pLogBuffer == 0)
    return CLStatus(-1, 0);
  if (m_nUsedBytesForBuffer == 0)
    return CLStatus(0, 0);

  ssize_t r = write(m_Fd, m_pLogBuffer, m_nUsedBytesForBuffer);

  if (r == -1)
    return CLStatus(-1, errno);
  m_nUsedBytesForBuffer = 0;
  return CLStatus(0, 0);

}


