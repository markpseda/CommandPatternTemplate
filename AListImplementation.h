#pragma once
#include "ListInterface.h"
#include "A.h"
class AListImplementation : public ListInterface<A>
{
  public:
  virtual std::vector<A> GetAllItems() override
  {
    return m_List;
  }

  virtual A* GetItemWriteAccess(int index) override
  {
    A* res = nullptr;

    if(index < 0 || index > m_List.size())
    {
      return res;
    }

    return &(m_List.at(index));
  }

  virtual void AddItem(A a) override
  {
    m_List.push_back(a);
  }

  private:
  std::vector<A>  m_List;
};