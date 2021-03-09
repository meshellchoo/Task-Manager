#ifndef __TASKMANAGER_CPP__
#define __TASKMANAGER_CPP__

#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"


//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"

//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskManager.hpp"



TaskManager::TaskManager(){
	TaskBank* taskBank = new TaskBank();
	TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
}
TaskManager::~TaskManager(){
	delete taskBank;
	delete taskBankCommand;
}
void TaskManager::run(){
	char answer;
	bool quit = false;
	printMenu();
	do{
	std::cout << "  :";
	std::cin >> answer;
	switch(toupper(answer)){
	case '1':
		std::cout << "case 1" << std::endl;
		taskBank->addTask(getTaskFromUser());
		std::cout << "after adding task"  << std::endl;
		break;				
	case '2':
		taskBank->addTask(getTaskListFromUser());
		break;
	case '3':
		break;
	case '4':
		//taskBank.deleteTask();
		break;
	
	}
	}while(!quit);
	printMenu();
	
}


#endif 
