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
        std::cout << "    Description: " <<  description << std::endl;
	std::cout << "    Type of Task: " << taskType << std::endl;
        std::cout << "    Priority: " << priority << std::endl;
	std::cout << "    Due Date: " << dueDate << std::endl;
}


bool Task::isTaskList(){
	return false;
}
#endif 
