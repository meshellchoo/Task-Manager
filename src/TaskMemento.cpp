#ifndef __TASKMEMENTO_CPP__
#define __TASKMEMENTO_CPP__

#include "TaskMemento.hpp"

// Constructor
TaskMemento::TaskMemento(TaskObject* taskSave){ //stores task object
	this->currentTask = taskSave;
}

TaskObject* TaskMemento::getSavedTask(){ // returns which task object is in the memento
	return currentTask;
}


#endif 
