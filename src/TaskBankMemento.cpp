//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankMemento.hpp"

#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankMemento.hpp"

//#include"/home/csmajs/htran164/cs100-task-manager/header/TaskBankMemento.hpp"



TaskBankMemento::TaskBankMemento(std::vector<TaskObject*> taskBank)
{	/*
	std::vector<TaskObject*> copyTaskBank;
	for(int i = 0; i <  taskBank.schedule.size(); i ++){
		TaskObject* t = taskBank[i];
		if(t->isTaskList()){
			copyTaskBank.push_back(new TaskList(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate(),static_cast<TaskList*>(t)->getSubTasks()));
		}else{
			copyTaskBank.push_back(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
		}
	}
	this->taskBank = copyTaskBank;
*/
	this->taskBank = taskBank;
}

std::vector<TaskObject*> TaskBankMemento::getTaskBank(){
	std::vector<TaskObject*> copyTaskBank;
        for(int i = 0; i <  taskBank.size(); i ++){
                TaskObject* t = taskBank[i];
                if(t->isTaskList()){
                        copyTaskBank.push_back(new TaskList(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate(),static_cast<TaskList*>(t)->getSubTasks()));
                }else{
                        copyTaskBank.push_back(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
                }
        }
	return copyTaskBank;
}

void TaskBankMemento::clear(){
        for(int i = 0; i < taskBank.size(); i++){
                delete taskBank[i];
                taskBank[i] = nullptr;
        }
        taskBank.clear();
}

TaskBankMemento::~TaskBankMemento(){
	for(int i = 0; i < taskBank.size(); i++){
                delete taskBank[i];
                taskBank[i] = nullptr;
        }
        taskBank.clear();
}

