#ifndef __TASKLIST_HPP__
#define __TASKLIST_HPP__
#include <vector>
//#include "TaskObject.hpp"
#include "Task.hpp"
#include "TaskMemento.hpp"

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
	std::vector<Task> getSubTasks();

        bool isTaskList();

};

#endif //__TASKLISTT_HPP__
