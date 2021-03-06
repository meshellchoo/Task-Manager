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

virtual void Task::setTaskState(Task newTask){
        std::cout << "From Originator: Current Version of Task\n" <<  newTask->getTaskName() << std::endl;
        task = newTask;
}

virtual TaskMemento Task::storeInMemento(){
        std::cout << "From Originator: Saving to Memento" << std::endl;
        return new TaskMemento(task);
}

virtual TaskObject* Task::restoreFromTaskMemento(TaskMemento taskMemento){
        task = taskMemento->getSavedTask();
        std::cout << "From Originator: Previous Task Saved Memento\n" << task->getTaskName() << std::endl;
        return task;
}

#endif 