#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include <vector>
#include "TaskObject.hpp"
#include "Task.hpp"
//#include "TaskMemento.hpp"

class TaskList: public TaskObject{
    private:
        std::vector<TaskObject*> tasks;
	
    public:
 	TaskList(std::string taskName, std::string description, 
        std::string taskType, int priority,Date dueDate, 
        std::vector<TaskObject*> subTasks);

	TaskList(std::string taskName, std::string description,
        std::string taskType, int priority,Date dueDate);

        void clear();
        bool deleteTask(TaskObject* task);
        void addTask(TaskObject* task);
        void sortByPriority();
	void sortByDueDate();
        void viewTask();

//	void setTaskState(TaskObject* newTaskList);
//        TaskMemento storeInMemento();
//        TaskObject* restoreFromTaskMemento(TaskMemento taskMemento);

};

#endif //__TASKLISTT_HPP__
