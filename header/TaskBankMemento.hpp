#ifndef __TASKBANKMEMENTO_CPP__
#define __TASKBANKMEMENTO_CPP__

#include <vector>
#include "TaskObject.hpp"

class TaskBankMemento
{
  public:
    TaskBankMemento(std::vector<TaskObject*> taskBank);
    std::vector<TaskObject*> getTaskBank();
  private:
    friend class TaskObject; // not essential, but p287 suggests this
    std::vector<TaskObject*> taskBank;
	
};


#endif
