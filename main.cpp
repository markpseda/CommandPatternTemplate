#include <iostream>
#include <memory>
#include <vector>
#include "A/A.h"
int main() 
{
  A a;
  a.name = "first";
  a.a = 1;
  a.b = 2;
  a.c = 3;
  std::cout << a.ToString() << std::endl;
  std::cout << "This is main from replit." << std::endl;
}