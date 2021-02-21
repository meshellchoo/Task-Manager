#ifndef __TASK_CPP__
#define __TASK_CPP__

//#include "/header/Task.hpp" 
#include "/home/csmajs/mchu017/cs100-task-manager/header/Task.hpp"
#include <iostream>


Task::Task(std::string taskName, std::string description, std::string taskType, int priority, std::string  dueDate){
	this->taskName = taskName;
	this->description = description;
	this->taskType = taskType;
	this->priority = priority;
	this->dueDate = dueDate;

}
void Task::viewTask(){
	std::cout << "- " << taskName << std::endl;
	std::cout << "  Type of Task: " << taskType << std::endl;
	std::cout << "  description:" <<  description << std::endl;
	std::cout << "  Due Date:" << dueDate << std::endl;
}
TaskObject* Task::createTaskMemento(){
    
}
//void Task::restore(TaskMemento t){

//}

#endif 
