#ifndef __TASKBANK_CPP__
#define __TASKBANK_CPP__

#include <vector>
#include <algorithm>



#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBank.hpp"
//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskBank.hpp"
//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBank.hpp"

#include <string>
#include <iostream>

TaskBank::TaskBank(){}

TaskBank::TaskBank(const TaskBank& copyThis){
	for(int i = 0; i <  copyThis.schedule.size(); i ++){
		TaskObject* t = copyThis.schedule[i];
		if(t->isTaskList()){
			schedule.push_back(new TaskList(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate(),static_cast<TaskList*>(t)->getSubTasks()));
		}else{
			schedule.push_back(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
		}
	}
}

TaskBank& TaskBank::operator =(const TaskBank& RHS){
	if(this == &RHS)
		return *this;
	this->clear();

	for(int i = 0; i <  RHS.schedule.size(); i ++){
		TaskObject* t = RHS.schedule[i];
        	if(t->isTaskList()){
                        schedule.push_back(new TaskList(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate(),static_cast<TaskList*>(t)->getSubTasks()));
                }else{
                        schedule.push_back(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
                }
        }
	
}


TaskBank::~TaskBank(){
	for(int i = 0; i < schedule.size(); i++){
                delete schedule[i];
                schedule[i] = nullptr;
        }
        schedule.clear();

}

void TaskBank::clear(){
	for(int i = 0; i < schedule.size(); i++){
		delete schedule[i];
		schedule[i] = nullptr;
	}	
        schedule.clear();
}

void TaskBank::display(){
	for(int i = 0; i < schedule.size(); i++){
		schedule[i]->viewTask();
	}
}

void TaskBank::addTask(TaskObject* task){
	schedule.push_back(task);
}

bool TaskBank::deleteTask(TaskObject* task){
	for(int i = 0; i < schedule.size(); i++){
		if (schedule[i] == task){
			schedule.erase(schedule.begin()+i);
			return true;
		}
		else {
			return false;
		}
	}
}


bool dueDateComparator(TaskObject* i, TaskObject* j)
{	
	Date i_temp = i->getTaskDueDate();
	Date j_temp = j->getTaskDueDate();

	if (i_temp.year != j_temp.year)
		return (i_temp.year < j_temp.year);
	else if (i_temp.month != j_temp.month)
		return (i_temp.month < j_temp.month);
	else if (i_temp.day != j_temp.day)
		return(i_temp.day < j_temp.day);
	else
		return ( i->getTaskPriority()  >= j->getTaskPriority());

	return true;
}



bool priorityComparator(TaskObject* i, TaskObject* j){ 
	if(i->getTaskPriority() != j->getTaskPriority())
		return (i->getTaskPriority()  >= j->getTaskPriority());
	return dueDateComparator(i,j);
		
}



void TaskBank::sortByPriority(){
	std::sort(schedule.begin(), schedule.end(), priorityComparator);
}

void TaskBank::sortByDueDate(){
	std::sort(schedule.begin(), schedule.end(), dueDateComparator);
}

TaskBankMemento* TaskBank::createTaskBankMemento()
{
    return new TaskBankMemento(schedule);
}
void TaskBank::restore(TaskBankMemento* taskBankMemento)
{
    schedule = taskBankMemento->getTaskBank();
}
#endif
