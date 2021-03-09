#ifndef __TASKBANKMEMENTO_CPP__
#define __TASKBANKMEMENTO_CPP__

#include <vector>
#include "TaskList.hpp"
#include "Task.hpp"
class TaskBankMemento
{
  public:
    TaskBankMemento(std::vector<TaskObject*> taskBank);
    std::vector<TaskObject*> getTaskBank();
    ~TaskBankMemento();
    void clear();
  private:
    friend class TaskObject; // not essential, but p287 suggests this
    std::vector<TaskObject*> taskBank;
	
};


#endif
