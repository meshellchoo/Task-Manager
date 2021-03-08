#ifndef __TASKBANK_CPP__
#define __TASKBANK_CPP__

#include <vector>
#include "/header/TaskBank.hpp"
#include <string>
#include <iostream>

TaskBank::TaskBank(){}


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
		if (schedule[i].getTaskName() == task.getTaskName()){
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

void TaskBank::setTaskState(TaskBank newTaskBank){
	std::cout << "From Originator: Setting Current TaskBank State" << std::endl;
        currentTaskBank = newTaskBank;
}

TaskBankMemento TaskBank::storeInTaskBankMemento(){
        std::cout << "From Originator: Saving Current TaskBank to Memento" << std::endl;
        return TaskBankMemento(currentTaskBank);
}

TaskBank TaskBank::restoreFromTaskBankMemento(TaskBankMemento taskBankMemento){
        currentTaskBank = taskBankMemento.getSavedTaskBank();
        std::cout << "From Originator: Reverting Back to Previous TaskBank State" << std::endl;
        return currentTaskBank;
}


#endif
