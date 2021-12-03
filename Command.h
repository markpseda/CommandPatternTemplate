#pragma once
// Interface
class Command
{
  public:
  virtual void execute() = 0;
  virtual bool getSuccess() = 0;
};