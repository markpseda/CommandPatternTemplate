#include "CommandUndoable.h"
#include<list>
#include<memory>

/*
Composite commands are for the case where a group of un-doable commands must
all be executed together, or else should not be executed. In the case where
some but not all commands succeeded, the previously executed commands are 
undone.

The composite command itself cannot be undone.
*/
class CompositeCommand : public Command
{
  public:
  CompositeCommand();

  virtual void Add(std::shared_ptr<CommandUndoable> l_command);
  virtual void Remove(std::shared_ptr<CommandUndoable> l_command);

  void execute() override;

  private:
  std::list<std::shared_ptr<CommandUndoable>> m_Commands;

};