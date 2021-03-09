#ifndef __TASKMANAGER_CPP__
#define __TASKMANAGER_CPP__

#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"


//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"

//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskManager.hpp"



TaskManager::TaskManager(){
	taskBank = new TaskBank();
	taskBankCommand = new TaskBankCommand(taskBank);
	taskBankCommand->Backup();
}
TaskManager::~TaskManager(){
	delete taskBankCommand;
}
void TaskManager::run(){
	int undoTimes = 0;
	char answer;
	bool quit = false;
//	printMenu();
	do{
	printMenu();
	std::cout << "  :";
	std::cin >> answer;
	switch(toupper(answer)){
	case '1':
		taskBank->addTask(getTaskFromUser());
		taskBankCommand->Backup();
		std::cout << "=========================" << std::endl;
		std::cout << "Successfully added task!" << std::endl;
		std::cout << "=========================" << std::endl;
		taskBank->display();
		break;				
	
	case '2':
		taskBank->addTask(getTaskListFromUser());
		taskBankCommand->Backup();
		break;
	case '3':
		std::cout << "which task do you want to edit?" << std::endl;
		
	//	taskBank.editTask();
		break;
	case '4':
		std::cout << "which task do you want to delete?" << std::endl;
	//	taskBank.deleteTask();
		break;
	case '5':
		taskBank->display();
		break;
	case '6': 
		if(undoTimes == 0){
			taskBankCommand->Undo();
			taskBankCommand->Undo();
		}else{
			taskBankCommand->Undo();	
		}
//		taskBankCommand->Undo();
//		taskBankCommand->Undo();
		undoTimes++;
		break;
	case 'X':
		quit = true;
		break;
	}
	}while(!quit);
	
	

}


#endif 
