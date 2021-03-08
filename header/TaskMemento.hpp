#ifndef __TASKMEMENTO_HPP__
#define __TASKMEMENTO_HPP__

#include "TaskObject.hpp"
//#include "Task.hpp"
//#include "TaskList.hpp"

class TaskMemento {

    private:
        TaskObject* currentTask;

    public:
	TaskMemento(TaskObject* taskSave);
        TaskObject* getSavedTask();

};
#endif //__TASKMEMENTO_HPP__
