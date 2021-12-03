#include <iostream>
#include <memory>
#include <vector>
#include "A.h"
#include "AListImplementation.h"
#include "IncrementACommand.h"
int main() 
{
  A a;
  a.name = "first";
  a.a = 1;
  a.b = 2;
  a.c = 3;

  std::shared_ptr<ListInterface<A>> aList = std::make_shared<AListImplementation>();

  aList->AddItem(a);


  std::vector<A> items = aList->GetAllItems();

  std::cout << "Before modification: " << std::endl;
  for(auto& i : items)
  {
    std::cout << i.ToString() << std::endl;
  }

  std::shared_ptr<Command> incrementACommand = std::make_shared<IncrementACommand>(aList, 4);


  std::vector<std::shared_ptr<Command>> l_Commands;

  l_Commands.push_back(incrementACommand);


  for(auto& command : l_Commands)
  {
    command->execute();
  }

  items = aList->GetAllItems();

  std::cout << "After modification: " << std::endl;
  for(auto& i : items)
  {
    std::cout << i.ToString() << std::endl;
  }

}