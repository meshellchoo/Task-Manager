#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "TaskObject.hpp"


class Task : public TaskObject{
    private:
 
    public:
        Task();
	Task(std::string taskName, std::string description, std::string taskType,
		 int priority, std::string dueDate);
	void viewTask();


	 virtual TaskObject* createTaskMemento();
//        virtual void restore(TaskMemento t);

};

#endif //__TASK_HPP__

