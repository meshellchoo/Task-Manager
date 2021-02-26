#ifndef __TASKOBJECT_HPP__
#define __TASKOBJECT_HPP__
#include <string>
#include "TaskMemento.hpp"
#include "Date.hpp"
#include <string>
#include <iostream>

class TaskObject {

    protected:
	std::string taskName;
	std::string description;
	std::string taskType;
	int priority;
	Date dueDate;  
	TaskObject* task;	
    public:
	
        /* Constructors */
        virtual void viewTask() = 0;
        void setTaskName(std::string taskName)
		{this->taskName = taskName;};
        void setTaskType(std::string taskType)
		{this->taskType = taskType;};
        void setTaskDescription(std::string description)
		{this->description = description;};
        void setTaskDueDate(Date dueDate)
		{this->dueDate = dueDate;};
	void setTaskPriority(int priority){this->priority = priority;}
	std::string getTaskName()const{return taskName;}
	std::string getTaskType()const
		{return taskType;}
        std::string getTaskDescription()const
		{return description;}
        int getTaskPriority()const
		{return priority;}
        Date getTaskDueDate()const
		{return dueDate;}
	
	virtual void setTaskState(TaskObject* newTask){
		std::cout << "From Originator: Current Verision of Task\n" <<  newTask.getName() << std::endl;
		task = newTask;		
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

#endif //__TASKOBJECT_HPP__
