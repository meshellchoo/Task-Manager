#ifndef __TASKMEMENTO_HPP__
#define __TASKMEMENTO_HPP__

#include "TaskObject.hpp"

class TaskMemento{
    private:
        TaskObject* task;
    public:
	TaskMemento(TaskObject* taskSave){};
        TaskObject* getSavedTask();

};

#endif //__TASKMEMENTO_HPP__
