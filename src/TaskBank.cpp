#ifndef __TASKBANK_CPP__
#define __TASKBANK_CPP__

#include <vector>
#include "/header/TaskBank.hpp"
#include <string>
#include <iostream>

TaskBank::TaskBank(){ // Default Constructor
	this->schedule = schedule;
}

TaskBank::~TaskBank(){
	for(int i = ; i < schedule.size(); i++){
		delete schedule[i];
		schedule[i] = nullptr;
	}
	schedule.clear();	
}

void TaskBank::clear(){
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

}

//		TaskObject* createTaskBankMemento();
//		//		void restore(taskBankMemento);
//
//		}

std::vector& operator=(const std::vector &v){
	if(size != v.size){
		cerr << "FATAL vector::operator(const vector &) size mismatch: " <<
			size << " " << v.size << "\n";
		exit(1);
	}
	for(int i = 0; i < size; i++)vec[i] = v.vec[i];
		 return *this;
}

#endif
