#ifndef __TASKMEMENTO_CPP__
#define __TASKMEMENTO_CPP__

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankMemento.hpp"
//nclude "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankMemento.hpp"
//nclude "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankMemento.hpp"



// Constructor
TaskBankMemento::TaskBankMemento(TaskBank taskBankSave){ //stores task object
	currentTaskBank = taskBankSave;
}

// Functions
TaskBank TaskBankMemento::getSavedTaskBank(){ // returns which task object is in the memento
	return currentTaskBank;
}


#endif 
