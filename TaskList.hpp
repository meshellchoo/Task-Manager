#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include "Task.hpp"
#include <vector>


class TaskList{
    private:
        std::vector<Task> tasks;
    public:
        void clear();
        void deleteTask(Task task);
        void addTask(Task task);
        virtual void viewTask();
        virtual TaskObject* createTaskMemento();
        //virtual void restore(TaskMemento t);
};

#endif //__TASKLIST_HPP__

