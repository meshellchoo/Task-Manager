#ifndef __TASKMANAGER_CPP__
#define __TASKMANAGER_CPP__

//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"
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
	case '4':{
		std::string taskName;
		std::cout << "which task do you want to delete?" << std::endl;
		std::cout << "  :";
		std::cin >> taskName;
		if(taskBank->deleteTask(taskName)){
			std::cout << "the task has been deleted" << std::endl;
			taskBankCommand->Backup();
		}else{
			std::cout << "the task could not be found" << std::endl;
		}
		break;
	}
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
		undoTimes++;
		break;
	case '7':{
		std::string taskName;
		std::cout << "Please enter a task to search for" << std::endl;
		std::cin >> taskName;
		std::vector<TaskObject*> found = taskBank->search(taskName);
		if(found.size() == 0){
			std::cout << "The task was not found" << std::endl;
		}else{
			std::cout << "The tasks that matched your search: " << std::endl;
			for (int i = 0; i < found.size(); i++){
                        	found[i]->viewTask();
                	}
		}
	}
	case '8':{
		char choice;
		printSortMenu();
		std::cout << "  :";
		std::cin >> choice;
		if(choice == '1'){
			taskBank->sortByDueDate();
			taskBankCommand->Backup();		
		}else if(choice == '2'){
			taskBank->sortByPriority();
			taskBankCommand->Backup();
		}else{
			std::cout << "not a valid input!" << std::endl;
		}
		break;
	}
	case 'X':
		quit = true;
		break;
	}
	}while(!quit);
	
	

}


#endif 
