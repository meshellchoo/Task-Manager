#ifndef __TASK_CPP__
#define __TASK_CPP__

#include "/home/csmajs/jooi001/cs100-task-manager/header/Task.hpp" 
//#include "/home/csmajs/mchu017/cs100-task-manager/header/Task.hpp"
//#include "/home/csmajs/htran164/cs100-task-manager/header/Task.hpp"
#include <iostream>


Task::Task(std::string taskName, std::string description, std::string taskType, int priority, Date dueDate) :TaskObject(){
	this->taskName = taskName;
	this->description = description;
	this->taskType = taskType;
	this->priority = priority;
	this->dueDate = dueDate;

}
void Task::viewTask(){
	std::cout << "- " << taskName << std::endl;
	std::cout << "  Type of Task: " << taskType << "task" << std::endl;
	std::cout << "  description: " <<  description << std::endl;
	std::cout << "  Due Date: " << dueDate << std::endl;
}

/*
void Task::setTaskState(TaskObject* newTask){
        std::cout << "From Originator: Current Version of Task\n" <<  newTask->getTaskName() << std::endl;
        currentTask = newTask;
}

TaskMemento Task::storeInMemento(){
        std::cout << "From Originator: Saving to Memento" << std::endl;
        return TaskMemento(currentTask);
}

TaskObject* Task::restoreFromTaskMemento(TaskMemento taskMemento){
        currentTask = taskMemento.getSavedTask();
        std::cout << "From Originator: Previous Task Saved Memento\n" << currentTask->getTaskName() << std::endl;
        return currentTask;
}
*/
#endif 
