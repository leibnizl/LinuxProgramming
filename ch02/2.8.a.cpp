#include <iostream>

class A
{
public:
  A()
  {
    std:: cout << "In A(): " << hex << (long)this << std:: endl;
  }

  A(const A&)
  {
    std:: cout << "In A(const A&): " << hex << (long)this << std:: endl;
  }

  A& operator=(const A& a)
  {
    std:: cout << "In operator=: " << hex << (long)this << " = " << hex << (long)(&a) << std:: endl;
    return *this
  }
};

A f()
{
  A b;
  return b;
}

int _tmain(int argc, std:: _TCHAR* argv[])
{
  A a;
  a = f();
  return 0;
}
