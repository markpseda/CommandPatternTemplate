#pragma once
#include "CommandUndoable.h"
#include "ListInterface.h"
/*
Increment all the 'a's in an AList

*/
class IncrementACommand : public CommandUndoable
{
  public:

  IncrementACommand(std::shared_ptr<ListInterface<A>> l_ListInterface, int l_amount)
  {
    m_ListInterface = l_ListInterface;
    m_Amount = l_amount; 
  }

  void execute() override
  {
    if(!m_ListInterface.get())
    {
      std::cout << "List interface undefined.";
      m_bSuccess = false;
      return;
    }

    auto listSize = m_ListInterface->GetAllItems().size();

    for(int i = 0; i < listSize; i++)
    {
      A* item = m_ListInterface->GetItemWriteAccess(i);
      if(item)
      {
        item->a = item->a + m_Amount;
      }
    }

    m_bSuccess = true;
  }

  void undo() override
  {
    if(!m_ListInterface)
    {
      m_bSuccess = false;
      std::cout << "List interface undefined.";
      return;
    }

    auto listSize = m_ListInterface->GetAllItems().size();

    for(int i = 0; i < listSize; i++)
    {
      A* item = m_ListInterface->GetItemWriteAccess(i);
      if(item)
      {
        item->a -= m_Amount;
      }
    }
  }

  bool getSuccess() override
  {
    return m_bSuccess;
  }

  protected:
  int m_Amount;
  std::shared_ptr<ListInterface<A>> m_ListInterface;
  bool  m_bSuccess = false;

};