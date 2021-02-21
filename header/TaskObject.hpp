#ifndef __TASKOBJECT_HPP__
#define __TASKOBJECT_HPP__
#include <string>
#include "TaskMemento.hpp"

class TaskObject {

    protected:
	std::string taskName;
	std::string description;
	std::string taskType;
	int priority;
	std::string dueDate;

    public:
        /* Constructors */
        virtual void viewTask() = 0;
        void setTaskName(std::string taskName)
		{this->taskName = taskName;};
        void setTaskType(std::string taskType)
		{this->taskType = taskType;};
        void setTaskDescription(std::string description)
		{this->description = description;};
        void setTaskDueDate(std::string dueDate)
		{this->dueDate = dueDate;};
	void setTaskPriority(int priority){this->priority = priority;}
	std::string getTaskName(){return taskName;}
	std::string getTaskType()
		{return taskType;}
        std::string getTaskDescription()
		{return description;}
        int getTaskPriority()
		{return priority;}
        std::string getTaskDueDate()
		{return dueDate;}
	
//	virtual TaskObject* createTaskMemento() = 0;
//        virtual void restore(TaskMemento t) = 0;
};

#endif //__TASKOBJECT_HPP__
