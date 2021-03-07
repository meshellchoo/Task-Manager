#ifndef __TASKOBJECT_CPP__
#define __TASKOBJECT_CPP__
#include "header/TaskObject.hpp"

	
void TaskObject::setTaskName(std::string taskName){this->taskName = taskName;}
void TaskObject::setTaskType(std::string taskType){this->taskType = taskType;}
void TaskObject::setTaskDescription(std::string description){this->description = description;}
void TaskObject::setTaskDueDate(Date dueDate){this->dueDate = dueDate;}
void TaskObject::setTaskPriority(int priority){this->priority = priority;}
std::string TaskObject::getTaskName()const{return taskName;}
std::string TaskObject::getTaskType()const{return taskType;}
std::string TaskObject::getTaskDescription()const{return description;}
int TaskObject::getTaskPriority()const{return priority;}
Date TaskObject::getTaskDueDate()const{return dueDate;}
	
// virtual TaskObject* createTaskMemento() = 0;
// virtual void restore(TaskMemento t) = 0;
};

#endif //__TASKOBJECT_CPP__
