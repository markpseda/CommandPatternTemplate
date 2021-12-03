#pragma once
#include "Command.h"

class CommandUndoable : public Command
{
  public:
  // Should reset state to that before any operation was performed
  virtual void undo() = 0;
};