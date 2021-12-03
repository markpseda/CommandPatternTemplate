#pragma once
#include <vector>

template<typename T>
class ListInterface
{
  public:
  virtual std::vector<T> GetAllItems() = 0;
  virtual T* GetItemWriteAccess(int index) = 0;
  virtual void AddItem(T item) = 0;
};