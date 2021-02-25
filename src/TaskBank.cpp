#ifndef __TASKBANK_CPP__
#define __TASKBANK_CPP__

#include <vector>
#include "/header/TaskBank.hpp"
#include <string>
#include <iostream>

TaskBank::TaskBank(){}

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
		schedule[i].viewTask();
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

void TaskBank::sortByPriority(){
	std::sort(schedule.begin(), schedule.end(), prioritySort);
}

void TaskBank::sortByDueDate(){
	std::sort(schedule.begin(), schedule.end(), dueDateSort());
}

//		TaskObject* createTaskBankMemento();
//		//		void restore(taskBankMemento);
//
//		}

TaskBank& operator=(const TaskBank& taskbank){
	for(int i = 0; i < schedule.size(); i++){
                delete schedule[i];
                schedule[i] = nullptr;
        }
        schedule.clear();

	for(int i = 0; i < taskbank.schedule.size(); i++){
		schedule.push_back(taskbank.schedule[i]);
	}
}

#endif
