#ifndef __TASKMEMENTO_CPP__
#define __TASKMEMENTO_CPP__

#include "TaskMemento.hpp"

TaskMemento::TaskMemento(TaskObject* stateToSave){
	this->stateToSave = stateToSave;
}

TaskObject* TaskMemento::getTaskState(){
	return stateToSave;
}

#endif 
