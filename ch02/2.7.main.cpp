#include <iostream>
#include "2.7.CLStatus.h"

CLStatus f()
{
  CLStatus s(-1, 2);
  return s;
}

int main()
{
  CLStatus s = f();
  if (!s.IsSuccess())
  {
    std:: cout << "f error" << std:: endl;
    std:: cout << "error code: " << s.m_clErrorCode << std:: endl;
  }

  return 0;
      
}
