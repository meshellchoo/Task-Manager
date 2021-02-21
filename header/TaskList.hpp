#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include <vector>
#include "TaskObject.hpp"
#include "Task.hpp"

class TaskList{
    private:
        std::vector<Task> tasks;
    public:
 	TaskList(std::string taskName, std::string description, 
        std::string taskType, int priority, std::string dueDate, 
        std::vector<Task> subTasks);
        void clear();
        void deleteTask(Task task);
        void addTask(Task task);
        virtual void viewTask();
        virtual TaskObject* createTaskMemento();
//        virtual void restore(TaskMemento t);
};

#endif //__TASKLISTT_HPP__
