#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include <vector>
#include "TaskObject.hpp"
#include "Task.hpp"

class TaskList: public TaskObject{
    private:
        std::vector<Task> tasks;
	
    public:
 	TaskList(std::string taskName, std::string description, 
        std::string taskType, int priority,Date dueDate, 
        std::vector<Task> subTasks);
	TaskList(std::string taskName, std::string description,
        std::string taskType, int priority,Date dueDate);
        void clear();
        bool deleteTask(Task task);
        void addTask(Task task);
        void sortByPriority();
	void sortByDueDate();
        void viewTask();
        virtual void setTaskState(TaskList newTaskList){
                std::cout << "From Originator: Current Version of Task\n" <<  newTaskList.getName() << std::endl;
                task = newTaskList;
        }

        virtual TaskMemento storeInMemento(){
                std::cout << "From Originator: Saving to Memento" << std::endl;
                return new TaskMemento(task);
        }

        virtual void restoreFromTaskMemento(TaskMemento taskMemento){
                task = taskMemento.getSavedTask();
                std::cout << "From Originator: Previous Task Saved Memento\n" << task.getName() << std::endl;
                return task;
        }

};

#endif //__TASKLISTT_HPP__
