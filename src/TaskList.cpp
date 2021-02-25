#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__
#include <iostream>
#include <algorithm>    // std::sort

//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
////#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp"


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

bool  TaskList::deleteTask(Task task){
    for(int i = 0; i < tasks.size(); i++){
            if(tasks[i].getTaskName()== task.getTaskName()){
		tasks.erase(tasks.begin() + i);
	   	return true;
	    }
    }
    return false;
}
void TaskList::addTask(Task task){
    tasks.push_back(task);
}
void TaskList::viewTask(){
	std::cout << "- " << taskName << std::endl;
	std::cout << "    Type of Task: " << taskType << " tasklist" <<  std::endl;
	std::cout << "    description: " <<  description << std::endl;
	std::cout << "    Due Date: " << dueDate << std::endl;
	for(int i = 0 ; i < tasks.size(); i++){
		std::cout << "      " ;
		std::cout << "- " << tasks[i].getTaskName() << std::endl;
		std::cout << "        " ;
      	 	std::cout << "  Type of Task: " << tasks[i].getTaskType() << std::endl;
		std::cout << "        " ;
	        std::cout << "  description: " << tasks[i].getTaskDescription() << std::endl;
		std::cout << "        " ;
	        std::cout << "  Due Date: " << tasks[i].getTaskDueDate() << std::endl;

	}

}

bool dueDateSort(Task i, Task j){ return (i.getTaskDueDate() <= j.getTaskDueDate());}


void TaskList::sortByPriority(){
	std::sort(tasks.begin(),tasks.end(),prioritySort);
}

void TaskList::sortByDueDate(){}

TaskObject* TaskList::createTaskMemento(){
    
}
//void TaskList::restore(TaskMemento t){

//}

#endif 
