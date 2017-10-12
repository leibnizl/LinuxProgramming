#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "2.12.CLLogger.h"

#define LOG_FILE_NAME "2.12.CLLogger.txt"
#define MAX_SIZE 265

CLLogger* CLLogger:: m_pLog = 0;

CLLogger:: CLLogger()
{
  m_Fd = open(LOG_FILE_NAME, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
}

CLLogger:: ~CLLogger()
{
  if (m_Fd != -1)
    close(m_Fd);
}

CLStatus CLLogger:: WriteLog(const char* pstrMsg, long lErrorCode)
{
  if (pstrMsg == 0)
    return CLStatus(-1, 0);

  if(strlen(pstrMsg) == 0)
    return CLStatus(-1, 0);
  int fd = open(LOG_FILE_NAME, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
  if (fd == -1)
    return CLStatus(-1, errno);
  ssize_t r  = write (fd, pstrMsg, strlen(pstrMsg));
  if (r == -1)
    {
      close(fd);
      return CLStatus(-1, errno);
    }

  char buf[MAX_SIZE];
  snprintf(buf, MAX_SIZE, " Error code: %ld\r\n", lErrorCode);

  r = write(fd, buf, strlen(buf));

  if (r == -1)
    {
      close(fd);
      return CLStatus(-1, errno);
    }
  close(fd);

  return CLStatus(0, 0);

}

CLLogger* CLLogger:: GetInstance()
{
  if (m_pLog == 0)
    m_pLog = new CLLogger;
  return m_pLog;
}

