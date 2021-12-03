#include "A.h"

std::string A::ToString()
{
  std::string res;
  res += name;
  res += std::to_string(a);
  res += std::to_string(b);
  res += std::to_string(c);

  return res;
}