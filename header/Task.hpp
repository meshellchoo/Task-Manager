#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "TaskObject.hpp"


class Task{
    private:
        
    public:
        virtual void viewTask();
        virtual TaskObject* createTaskMemento();
       // virtual void restore(TaskMemento t);

};

#endif //__TASK_HPP__

