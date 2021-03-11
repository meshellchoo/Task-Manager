#ifndef __HELPERFUNCTIONS_CPP__
#define __HELPERFUNCTIONS_CPP__
#include <iostream>
#include <locale>
#include <string>
#include "/home/csmajs/mchu017/cs100-task-manager/header/helperFunctions.hpp"
//#include "/home/csmajs/jooi001/cs100-task-manager/header/helperFunctions.hpp"

void printMenu(){
	std::cout << "*******************************" << std::endl;
	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "*******************************" << std::endl;
	std::cout << "(1): Add a task" << std::endl;
	std::cout << "(2): Add a tasklist" << std::endl;
	std::cout << "(3): Edit task" << std::endl;
	std::cout << "(4): Delete task" << std::endl;
	std::cout << "(5): Display Current Schedule" << std::endl;
	std::cout << "(6): Undo last action" << std::endl;
	std::cout << "(7): Search for a task" << std::endl;
	std::cout << "(8): Sort schedule" << std::endl;
	std::cout << "(x): Exit" << std::endl;
}

void printEditMenu(){
	std::cout << "*******************************" << std::endl;
        std::cout << "********** Edit Menu **********" << std::endl;
        std::cout << "*******************************" << std::endl;
        std::cout << "(1): Change a task name" << std::endl;
	std::cout << "(2): Change a task description" << std::endl;
	std::cout << "(3): Change a task type" << std::endl;
	std::cout << "(4): Change a task priority" << std::endl;
	std::cout << "(5): Change a task due date" << std::endl;
}

void printDeleteMenu(){
	std::cout << "*******************************" << std::endl;
        std::cout << "********* Delete Menu *********" << std::endl;
        std::cout << "*******************************" << std::endl;
	std::cout << "(1): Delete a whole Task/Tasklist" << std::endl;
  	std::cout << "(2): Delete a subtask from a Tasklist" << std::endl;
}
void printSortMenu(){
	std::cout << "*******************************" << std::endl;
        std::cout << "********** Sort Menu **********" << std::endl;
        std::cout << "*******************************" << std::endl;	
	std::cout << "(1): Sort by due date" << std::endl;
        std::cout << "(2): Sort by priority" << std::endl;
}
bool stringIsInt(std::string checkThis){
	for(int i = 0 ; i<checkThis.length(); i++){
		if(!isdigit(checkThis[i]))
			return false;
	}

	return true;
}

bool stringIsInt(std::string checkThis){
	for(int i = 0; i < checkThis.length();i++){
         	if(!isdigit(checkThis[i]))		
                	return false;
       	}
	return true;
}

Task* getTaskFromUser(){
	std::string taskName,taskDescription,taskType,priority;
        Date dueDate;
        std::cout << "Task Name: ";
	std::getline(std::cin >> std::ws, taskName);

       
        std::cout << "Description: ";
	std::getline(std::cin >> std::ws, taskDescription);
        
	
        std::cout << "Type of task: " ;
	std::getline(std::cin >> std::ws, taskType);

	
        std::cout << "Priority of Task (1-10): " ;
        std::cin >> priority;
	while (priority.length() > 2 ||(priority.length() > 0 && !std::isdigit(priority[0])) || (priority.length() == 2 && !std::isdigit(priority[1])) || stoi(priority) < 1 || stoi(priority) > 10){
		std::cout << "Invalid priority. Please re-enter the priority." << std::endl;
		std::cout << "Priority of Task (1-10): " ;	        
		std::cin >> priority;
	}

        
        std::cout << "Due Date (mm/dd/yyyy): " ;
        std::cin >> dueDate;
       
	return new Task(taskName,taskDescription,taskType,stoi(priority),dueDate);	
	
}

TaskList* getTaskListFromUser(TaskBank* taskBank){
        std::string taskName,taskDescription,taskType, priority;
        Date dueDate;
        std::cout << "Task List Name: " ;
        std::getline(std::cin >> std::ws, taskName);

 
        std::cout << "Description: " ;
        std::getline(std::cin >> std::ws, taskDescription);

   
        std::cout << "Type of task: " ;
        std::getline(std::cin >> std::ws, taskType);

     
        std::cout << "Priority of Task (1-10): " ;
        std::cin >> priority;
	while (priority.length() > 2 ||(priority.length() > 0 && !std::isdigit(priority[0])) || (priority.length() == 2 && !std::isdigit(priority[1])) || stoi(priority) < 1 || stoi(priority) > 10){
		std::cout << "Invalid priority. Please re-enter the priority." << std::endl;
		std::cout << "Priority of Task (1-10): " ;
	        std::cin >> priority;
	}

       
        std::cout << "Due Date (mm/dd/yyyy): " ;
        std::cin >> dueDate;
        TaskList* tempTaskList =  new TaskList(taskName,taskDescription,taskType, stoi(priority), dueDate);
        char answer;
	char initialAnswer;
	do{
	std::cout << "Would you like to add any subtasks into your tasklist? (Y/N)" << std::endl;
	std::cout << "   :";
	std::cin >> initialAnswer;
	while(toupper(initialAnswer) != 'Y' && toupper(initialAnswer) != 'N'){
		std::cout << "Invalid answer. Please re-enter your answer. (Y/N)" << std::endl;	
		std::cout << "   :";
		std::cin >> initialAnswer;
	}
	if(toupper(initialAnswer) == 'N'){
		return tempTaskList;
	}

	else{
		// use an existing task
		std::cout << "Would you like to add an existing task? (Y/N)" << std::endl;
		std::cout << "   :";
		std::cin >> answer;
	        while(toupper(answer) != 'Y' && toupper(answer) != 'N'){
        	        std::cout << "Invalid answer. Please re-enter your answer. (Y/N)" << std::endl;
			std::cout << "   :";
               		std::cin >> answer;
        	}
		if(toupper(answer) == 'Y'){
			std::string taskName;
			std::cout << "Please type the name of the task you want to add." << std::endl;
			std::cout << "   :";
			std::getline(std::cin >> std::ws, taskName);				
			std::vector<TaskObject*> found = taskBank->search(taskName);
			if(found.size() == 0){
				std::cout << "A task/task list with that name was not found." << std::endl;
			}else{
				std::cout << "Added \"" << found[0]->getTaskName() << "\" to the task list." << std::endl;
				TaskObject* t = found[0];
				tempTaskList->addTask(new Task(t->getTaskName(),t->getTaskDescription(),t->getTaskType(),t->getTaskPriority(),t->getTaskDueDate()));
				taskBank->deleteTask(found[0]);

			}
		}		

		// create new task
		else if(toupper(answer) == 'N'){
			std::cout << "Creating new task to add to task list" << std::endl;
			tempTaskList->addTask(getTaskFromUser());
		}
	}

	}while(toupper(initialAnswer) != 'N');
	return tempTaskList;
}

#endif
