#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "TaskObject.hpp"
class Task: public TaskObject{

    private:
 
    public:
        Task();
	Task(std::string taskName, std::string description, std::string taskType,
		 int priority, Date dueDate);
	void viewTask();

	void setTaskState(TaskObject* newTask);
        TaskMemento storeInMemento();
        TaskObject* restoreFromTaskMemento(TaskMemento taskMemento);
};

#endif //__TASK_HPP__
