#include "A.h"
#include <

class AListInterface
{
  public:
  virtual std::vector<A> GetAllItems() = 0;
  virtual T* GetItemWriteAccess(int index) = 0;
  virtual void AddItem(T item) = 0;
};
