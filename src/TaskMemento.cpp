#ifndef __TASKMEMENTO_CPP__
#define __TASKMEMENTO_CPP__

#include "TaskMemento.hpp"

TaskMemento::TaskMemento(TaskObject* taskSave){
	task = taskSave;
}

TaskObject* TaskMemento::getSavedTask(){
	return task;
}

#endif 
