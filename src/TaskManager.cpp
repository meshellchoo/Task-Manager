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
	std::cout << "   :";
	std::cin >> answer;
	switch(toupper(answer)){

	case '1':
		taskBank->addTask(getTaskFromUser());
		taskBankCommand->Backup();
		std::cout << "\n===============================" << std::endl;
		std::cout << "  Successfully added task!\n  Displaying Current Schedule" << std::endl;
		std::cout << "===============================" << std::endl;
		taskBank->display();

                std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;

		break;				
	
	case '2':
		taskBank->addTask(getTaskListFromUser(taskBank ));
		taskBankCommand->Backup();
                std::cout << "\n===============================" << std::endl;
                std::cout << "  Successfully added task list!\n  Displaying Current Schedule" << std::endl;
                std::cout << "===============================" << std::endl;
                taskBank->display();
                std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;
		break;
	
	case '3':{
		std::string answer;	
		std::string taskName;
		std::cout << "Which task do you want to edit?" << std::endl;
		std::cout << "   :";
		std::getline(std::cin >> std::ws, taskName);
		std::vector<TaskObject*> found = taskBank->search(taskName);
                if(found.size() == 0){
                	std::cout << "No such task with that name exists." << std::endl;
		}else{
	                std::cout << "\n===============================" << std::endl;
        	        std::cout << "Editing \"" << found[0]->getTaskName() << "\""<< std::endl;
        	        std::cout << "===============================" << std::endl;

			printEditMenu();
			std::cout << "   :";
			std::cin >> answer;
			while(!stringIsInt(answer) || ((stringIsInt(answer) && std::stoi(answer) < 1) || (stringIsInt(answer) && std::stoi(answer) > 5))){
				std::cout << "Invalid choice. Please re-enter the menu choice." << std::endl;
				printEditMenu();
				std::cout << "  :";
				std::cin >> answer;
			}

			if(answer == "1"){
				std::string taskName;
				std::cout << "Please enter a new name for the task: " << std::endl;
				std::getline(std::cin >> std::ws, taskName); // get user input
				found[0]->setTaskName(taskName);
			}
		
			else if(answer == "2"){
				std::string taskDescription;
				std::cout << "Please enter a new description for the task: " << std::endl;
                        	std::getline(std::cin >> std::ws, taskDescription);
                        	found[0]->setTaskDescription(taskDescription);
			}

                	else if(answer == "3"){
				std::string taskType;
                        	std::cout << "Please enter a new type for the task: " << std::endl;
                        	std::getline(std::cin >> std::ws, taskType);
                        	found[0]->setTaskType(taskType);
                	}

			else if(answer == "4"){
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

			else if(answer == "5"){
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
		std::string answer;
		std::string taskName;
		printDeleteMenu();
		std::cout << "   :";			
		std::cin >> answer;
		while(!stringIsInt(answer) ||((stringIsInt(answer) && std::stoi(answer) != 1) && (stringIsInt(answer) && std::stoi(answer) != 2))){ //validate input 
			std::cout << "Invalid choice. Please re-enter the choice." << std::endl;
			printDeleteMenu();
			std::cout << "  :";
			std::cin >> answer;
		}
		
		if(std::stoi(answer) == 1){// 1 means user wants to delete a whole task/tasklist
			std::cout << "Which task do you want to delete?" << std::endl;
			std::cout << "   :";
			std::cin >> taskName;
			if(taskBank->deleteTask(taskName)){
	        	        std::cout << "\n===============================" << std::endl;
	               	 	std::cout << "  Deleting " << taskName <<  std::endl;
		                std::cout << "===============================" << std::endl;
				std::cout << "\"" <<  taskName << "\" has been deleted!\n" << std::endl;
				taskBankCommand->Backup();
			}else{
				std::cout << "A task/task list with that name was not found.\n"  << std::endl;
			}
		}else{ //else input is 2 which means user wants to delete a subtask from tasklist
			std::cout << "Which tasklist did you want to delete a subtask from?" << std::endl;			
			std::cout << "   :";
			std::cin >> taskName;
			std::vector<TaskObject*> found = taskBank->search(taskName);
			if(found.size() == 0){ // if no such tasklist is found, we exit back to main menu
				std::cout << "No such tasklist with that name exists" << std::endl;
			}else{
				std::cout << "Which subtask did you want to delete?" << std::endl;
				found[0]->viewTask(); 
				std::cout << std::endl;
        	                std::cout << "   :";
	                        std::cin >> taskName;
				if(static_cast<TaskList*>(found[0])->deleteTask(taskName)){
					std::cout << "\"" <<  taskName <<"\" has been successfully deleted" << std::endl;
					taskBank->display();
				}else{
					std::cout << "No subtask with that name exists" << std::endl; // if no such task is found, we exit back to main menu
				}

			}
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
		taskBank->display();
		std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;

		break;

	case '7':{
		std::string taskName;
		std::cout << "Please enter a task name to search for." << std::endl;
		std::cout << "   :";
	        std::getline(std::cin >> std::ws, taskName);		
		std::vector<TaskObject*> found = taskBank->search(taskName);
		if(found.size() == 0){
			std::cout << "A task/task list with that name was not found." << std::endl;
		}else{
                	std::cout << "\n===============================" << std::endl;
			std::cout << "Tasks/Task lists that matched your search: " << std::endl;
                	std::cout << "===============================\n" << std::endl;
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
		std::cout << "   :";
		std::cin >> choice;
		
		while(!stringIsInt(choice) ||((stringIsInt(choice) && stoi(choice) != 1) && (stringIsInt(choice) && stoi(choice) != 2))){	
			std::cout << "Invalid choice. Please re-enter the menu choice (1 or 2)." << std::endl;
			std::cout << "   :";
			std::cin >> choice;
		}
		if(choice == "1"){
			taskBank->sortByDueDate();
			taskBankCommand->Backup();		
			std::cout << "\n===============================" << std::endl;
        	        std::cout << "  Displaying Current Schedule" << std::endl;
	                std::cout << "===============================" << std::endl;
			std::cout << "===============================" << std::endl;
			std::cout << "The schedule has been sorted by due date" << std::endl;
			std::cout << "===============================" << std::endl;
		}else{
			std::cout << "\n===============================" << std::endl;
        	        std::cout << "  Displaying Current Schedule" << std::endl;
	                std::cout << "===============================" << std::endl;
			std::cout << "===============================" << std::endl;
                        std::cout << "The schedule has been sorted by priority" << std::endl;
                        std::cout << "\n===============================" << std::endl;
			taskBank->sortByPriority();
			taskBankCommand->Backup();
		}
		
		taskBank->display();
		std::cout << "===============================" << std::endl;
                std::cout << "===============================\n" << std::endl;
		break;
	}

	case 'X':
		quit = true;
		break;
	}
	}while(!quit);
	
	

}


#endif 
