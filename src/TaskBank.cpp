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
	if (schedule.size() == 0){
		std::cout << "There are currently no tasks or task lists." << std::endl;
	}

	else{
		for(int i = 0; i < schedule.size(); i++){
			schedule[i]->viewTask();
		}
	}
}

void TaskBank::display(std::ostream& out) const{
        if (schedule.size() == 0){
                std::cout << "There are currently no tasks or task lists." << std::endl;
        }

        else{
                for(int i = 0; i < schedule.size(); i++){
                        schedule[i]->viewTask(out);
                }

        }
}

void TaskBank::addTask(TaskObject* task){
	schedule.push_back(task);
}

bool TaskBank::deleteTask(TaskObject* task){
	for(int i = 0; i < schedule.size(); i++){
		if (schedule[i] == task){
			delete schedule[i];
			schedule.erase(schedule.begin()+i);
			return true;
		}
	}
	return false;
}

bool TaskBank::deleteTask(std::string taskName){
        for(int i = 0; i < schedule.size(); i++){
                if (schedule[i]->getTaskName()  == taskName){
			delete schedule[i];
                        schedule.erase(schedule.begin()+i);
                        return true;
                }
        }
	return false;
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
	for(int i = 0; i < schedule.size();i++){
		if(schedule[i]->isTaskList())
			static_cast<TaskList*>(schedule[i])->sortByPriority();
	}
}

void TaskBank::sortByDueDate(){
	std::sort(schedule.begin(), schedule.end(), dueDateComparator);
	for(int i = 0; i < schedule.size();i++){
                if(schedule[i]->isTaskList())
                        static_cast<TaskList*>(schedule[i])->sortByDueDate();
        }

}

TaskBankMemento* TaskBank::createTaskBankMemento()
{

    std::vector<TaskObject*> _schedule;
    TaskObject* t;
    for(int i = 0; i < schedule.size(); i ++){
	t = schedule[i];
	if(t->isTaskList()){
		_schedule.push_back(new TaskList(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate(),static_cast<TaskList*>(t)->getSubTasks()));
	}else{
		_schedule.push_back(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
	}
    }
    t = nullptr;
    return new TaskBankMemento(_schedule);

}
void TaskBank::restore(TaskBankMemento* taskBankMemento)
{
    this->clear();
    schedule = taskBankMemento->getTaskBank();
     
    delete taskBankMemento;
}
std::string toUpperString(std::string temp){
	for(int i = 0; i < temp.size(); i++) {
    		temp[i] = toupper(temp[i]);
	}
	return temp;
}
std::vector<TaskObject*> TaskBank::search(std::string userSearch){
	std::vector<TaskObject*> foundTasks;
	for (int i = 0; i < schedule.size(); i++){
		std::string temp = toUpperString(schedule[i]->getTaskName());
		if(temp.find(toUpperString(userSearch)) != std::string::npos){		
			foundTasks.push_back(schedule[i]);
		}
	}
	return foundTasks;
}
#endif
