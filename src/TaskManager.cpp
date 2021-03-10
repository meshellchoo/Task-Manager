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
		std::cout << "\n===============================" << std::endl;
		std::cout << "  Successfully added task!\nDisplaying Current Schedule" << std::endl;
		std::cout << "===============================" << std::endl;
		taskBank->display();

                std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;

		break;				
	
	case '2':
		taskBank->addTask(getTaskListFromUser());
		taskBankCommand->Backup();
                std::cout << "\n===============================" << std::endl;
                std::cout << "Successfully added task list!Displaying Current Schedule" << std::endl;
                std::cout << "===============================" << std::endl;

                taskBank->display();
                std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;
		break;
	
	case '3':
		std::cout << "Which task do you want to edit?" << std::endl;
	//	taskBank.editTask();
		break;
	
	case '4':{
		std::string taskName;
		std::cout << "Which task do you want to delete?" << std::endl;
		std::cout << "  :";
		std::cin >> taskName;
		if(taskBank->deleteTask(taskName)){
	                std::cout << "\n===============================" << std::endl;
	                std::cout << "  Deleting " << taskName <<  std::endl;
	                std::cout << "===============================" << std::endl;

			std::cout << taskName << " has been deleted!\n" << std::endl;
			taskBankCommand->Backup();
		}else{
			std::cout << "A task/task list with that name was not found.\n"  << std::endl;
		}
		break;
	}

	case '5':
		std::cout << "\n===============================" << std::endl;
                std::cout << "  Displaying Current Schedule" << std::endl;
                std::cout << "===============================" << std::endl;

		taskBank->display();

		std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;
		
		break;

	case '6':
                std::cout << "\n===============================" << std::endl;
                std::cout << "    Undoing Last Action" << std::endl;
                std::cout << "===============================" << std::endl;

		if(undoTimes == 0){
			taskBankCommand->Undo();
			taskBankCommand->Undo();
		}else{
			taskBankCommand->Undo();	
		}
		undoTimes++;

		std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;

		break;

	case '7':{
		std::string taskName;
		std::cout << "Please enter a task name to search for\n  :";
	        std::getline(std::cin >> std::ws, taskName);		
//		std::cin >> taskName;
		std::vector<TaskObject*> found = taskBank->search(taskName);
		if(found.size() == 0){
			std::cout << "A task/task list with that name was not found." << std::endl;
		}
		
		else{
                	std::cout << "\n===============================" << std::endl;
			std::cout << "Tasks/Task lists that matched your search: " << std::endl;
                	std::cout << "===============================" << std::endl;
			for (int i = 0; i < found.size(); i++){
                        	found[i]->viewTask();
                	}
                std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;

		}
		break;
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
