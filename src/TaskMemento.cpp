#ifndef __TASKMEMENTO_CPP__
#define __TASKMEMENTO_CPP__

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskMemento.hpp"

// Constructor
TaskMemento::TaskMemento(TaskObject* taskSave){ //stores task object
	currentTask = taskSave;
}

// Functions
TaskObject* TaskMemento::getSavedTask(){ // returns which task object is in the memento
	return currentTask;
}


#endif 
