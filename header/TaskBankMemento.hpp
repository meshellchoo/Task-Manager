#ifndef __TASKBANKMEMENTO_HPP__
#define __TASKBANKMEMENTO_HPP__

#include "TaskBank.hpp"
//#include "Task.hpp"
//#include "TaskList.hpp"

class TaskBankMemento {
    private:
        TaskBank currentTaskBank;

    public:
	TaskBankMemento(TaskBank taskSave);
        TaskBank getSavedTaskBank();

};
#endif //__TASKMEMENTO_HPP__
