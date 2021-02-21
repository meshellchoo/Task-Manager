#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__
#include <iostream>
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"

TaskList::TaskList(std::string taskName, std::string description, std::string taskType, int priority, std::string  dueDate,std::vector<Task> subTasks){
	this->taskName = taskName;
	this->description = description;
	this->taskType = taskType;
	this->priority = priority;
	this->dueDate = dueDate;
	this->tasks = subTasks;
}
TaskList::TaskList(std::string taskName, std::string description, std::string taskType, int priority, std::string  dueDate){
	this->taskName = taskName;
	this->description = description;
	this->taskType = taskType;
	this->priority = priority;
	this->dueDate = dueDate;

}

void TaskList::clear(){
    tasks.clear();
}
void TaskList::deleteTask(Task task){
    for(std::vector<Task>::iterator i = tasks.begin(); i != tasks.end(); i++){
        if(i == task)
            tasks.erase(i);
    }
    
}
void TaskList::addTask(Task task){
    tasks.push_back(task);
}
void TaskList::viewTask(){
	std::cout << "- " << taskName << std::endl;
	std::cout << "  Type of Task: " << taskType << std::endl;
	std::cout << "  description:" <<  description << std::endl;
	std::cout << "  Due Date:" << dueDate << std::endl;
	for(int i = 0 ; i < tasks.size(); i++){
//		std::cout << 
		tasks[i].viewTask();
	}
}
TaskObject* TaskList::createTaskMemento(){
    
}
//void TaskList::restore(TaskMemento t){

//}

#endif 
