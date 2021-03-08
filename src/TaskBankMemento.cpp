//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankMemento.hpp"

#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankMemento.hpp"

//#include"/home/csmajs/htran164/cs100-task-manager/header/TaskBankMemento.hpp"



TaskBankMemento::TaskBankMemento(std::vector<TaskObject*> taskBank)
{
	this->taskBank = taskBank;
}

std::vector<TaskObject*> TaskBankMemento::getTaskBank(){
	return taskBank;
}

