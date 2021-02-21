#ifndef __TASKMEMENTO_HPP__
#define __TASKMEMENTO_HPP__

#include "taskObject.hpp"

class TaskMemento{
    private:
        TaskObject* savedTaskState;
    public:
	TaskMemento(TaskObject* stateToSave){
		savedTaskState = stateToSave;
	}
        TaskObject* getTaskState();
	TaskObject* setTaskState();

}

#endif //__TASKMEMENTO_HPP__
