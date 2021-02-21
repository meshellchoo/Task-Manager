#ifndef __TASK_CPP__
#define __TASK_CPP__

#include "/header/Task.hpp" 
#include <iostream>


void Task::viewTask(){
	std::cout << "- " << taskName << std::endl;
	std::cout << "Type: " << taskType << std::endl;
	std::cout << description << std::endl;
	std::cout << "Due Date" << dueDate << std::endl;
}
TaskObject* Task::createTaskMemento(){
    
}
void Task::restore(TaskMemento t){

}

#endif 
