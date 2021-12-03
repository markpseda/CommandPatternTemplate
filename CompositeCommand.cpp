#include "CompositeCommand.h"

void CompositeCommand::execute()
{
  auto iter = m_Commands.begin();

  bool bShouldUndo = false;

  while(iter != m_Commands.end())
  {
    (*iter)->execute();
    
    if((*iter)->getSuccess() == false)
    {
      bShouldUndo = true;
      break;
    }
    iter++;
  }

  if(!bShouldUndo)
  {
    return;
  }

  while(iter != m_Commands.begin())
  {
    (*iter)->undo();
    iter--;
  }

  (*iter)->undo();
}

void CompositeCommand::Add(std::shared_ptr<CommandUndoable> l_command)
{
  m_Commands.push_back(l_command);
}

void CompositeCommand::Remove(std::shared_ptr<CommandUndoable> l_command)
{
  m_Commands.remove(l_command);
}