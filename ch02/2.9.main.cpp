#include <iostream>
#include "2.9.CLLogger.h"

int main()
{
  CLLogger logger;
  CLStatus s = logger.WriteLog("this is an error", 5);
  if (!s.IsSuccess())
  {
    std:: cout << "logger error" << std:: endl;
  }

  else
  {
    std:: cout << "logger success" << std:: endl;
  }
}
