#ifndef __TASKOBJECT_CPP__
#define __TASKOBJECT_CPP__

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskObject.hpp"
//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskMemento.hpp"

//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskObject.hpp"
//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskMemento.hpp"

void TaskObject::setTaskName(std::string taskName)
	{this->taskName = taskName;}
void TaskObject::setTaskType(std::string taskType)
	{this->taskType = taskType;}
void TaskObject::setTaskDescription(std::string description)
	{this->description = description;}
void TaskObject::setTaskDueDate(Date dueDate)
	{this->dueDate = dueDate;}
void TaskObject::setTaskPriority(int priority)
	{this->priority = priority;}
std::string TaskObject::getTaskName()const
	{return taskName;}
std::string TaskObject::getTaskType()const{
	return taskType;}
std::string TaskObject::getTaskDescription()const
	{return description;}
int TaskObject::getTaskPriority()const
	{return priority;}
Date TaskObject::getTaskDueDate()const
	{return dueDate;}
	

/*
void TaskObject::setTaskState(TaskObject* newTask){ //sets value of task object
		std::cout << "From Originator: Current Verision of Task\n" <<  newTask->getTaskName() << std::endl;
		currentTask = newTask;		
	}

TaskMemento TaskObject::storeInMemento(){ //saves current task into a task memento
		std::cout << "From Originator: Saving to Memento" << std::endl;
		return TaskMemento(currentTask); // memento constructor will pass in the currentTask values
	}

TaskObject* TaskObject::restoreFromTaskMemento(TaskMemento taskMemento){ //basically the undo function
		currentTask = taskMemento.getSavedTask(); //reverts back to the previous version that is stored in memento
		std::cout << "From Originator: Previous Task Saved Memento\n" << currentTask->getTaskName() << std::endl;
		return currentTask; // currentTask is now its previous state
	}
*/


#endif //__TASKOBJECT_CPP__
