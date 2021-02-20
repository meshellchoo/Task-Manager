#ifndef __TASK_HPP__
#define __TASK_HPP__
#include "taskObject.hpp"

class Task{
    private:
        
    public:
	Task(std::string taskName);
        virtual void viewTask();
        virtual TaskObject* createTaskMemento();
       // virtual void restore(TaskMemento t);
};

#endif //__TASK_HPP__

