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
	
	case '3':{
		int answer;	
		std::string taskName;
		std::cout << "Which task do you want to edit?" << std::endl;
		std::getline(std::cin >> std::ws, taskName);
		std::vector<TaskObject*> found = taskBank->search(taskName);
                if(found.size() == 0){
                	std::cout << "No such task with that name exists" << std::endl;
                }

		else{
		//handle this however you think should it shud be handled

			printEditMenu();
			std::cout << "  :";
			std::cin >> answer;
			while(answer < 1 || answer > 6){
				std::cout << "Invalid choice. Please re-enter the menu choice." << std::endl;
				printEditMenu();
				std::cout << "  :";
			}

			if(answer == 1){ // move task into task list
		
			}

			else if(answer == 2){
				std::string taskName;
				std::cout << "Please enter a new name for the task: " << std::endl;
				std::getline(std::cin >> std::ws, taskName); // get user input
				found[0]->setTaskName(taskName);

			}
		
			else if(answer == 3){
				std::string taskDescription;
				std::cout << "Please enter a new description for the task: " << std::endl;
                        	std::getline(std::cin >> std::ws, taskDescription);
                        	found[0]->setTaskDescription(taskDescription);
			}

                	else if(answer == 4){
				std::string taskType;
                        	std::cout << "Please enter a new type for the task: " << std::endl;
                        	std::getline(std::cin >> std::ws, taskType);
                        	found[0]->setTaskType(taskType);
                	}

			else if(answer == 5){
				std::string priority;
				std::cout << "Please enter a new priority (1-10): " << std::endl;
				std::cin >> priority;
                        	while (priority.length() > 2 ||(priority.length() > 0 && !std::isdigit(priority[0])) || (priority.length() == 2 && !std::isdigit(priority[1])) || stoi(priority) < 1 || stoi(priority) > 10){
					std::cout << "Invalid priority. Please re-enter the priority." << std::endl;
					std::cout << "New priority of task (1-10): " ;
		        		std::cin >> priority;
				}
                        	found[0]->setTaskPriority(stoi(priority));
			}

			else if(answer == 6){
				Date dueDate;
				std::cout << "Please enter a new due date (mm/dd/yyyy): " << std::endl;
                        	std::cin >> dueDate;
                        	found[0]->setTaskDueDate(dueDate);
		}	
		
		
			taskBankCommand->Backup();
		}
		break;

	}
	
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
		std::string choice;
		printSortMenu();
		std::cout << "  :";
		std::cin >> choice;
		while (stoi(choice) < 1 || stoi(choice) > 2){		
                       	std::cout << "Invalid input. Please re-enter the sort method (1 or 2)." << std::endl;
			std::cout << "  :";
                        std::cin >> choice;
		}
                
		if(choice == "1"){
			taskBank->sortByDueDate();
                        taskBankCommand->Backup();
                }

                else if(choice == "2"){
                        taskBank->sortByPriority();
                        taskBankCommand->Backup();
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
