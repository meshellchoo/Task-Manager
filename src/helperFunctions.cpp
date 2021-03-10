#ifndef __HELPERFUNCTIONS_CPP__
#define __HELPERFUNCTIONS_CPP__
#include <iostream>
#include <locale>
#include <string>
//#include "/home/csmajs/mchu017/cs100-task-manager/header/helperFunctions.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/helperFunctions.hpp"

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
	std::cout << "(8): Sort list" << std::endl;
	std::cout << "(x): Exit:" << std::endl;
//  	std::cout << "(6): Sort schedule by due date" << std::endl;
//	std::cout << "(7): Sort schedule by priority" << std::endl;
//	std::cout << "(8): Sort schedule by type of task" << std::endl;
	
}

void printEditMenu(){
	std::cout << "*******************************" << std::endl;
        std::cout << "********** Edit Menu **********" << std::endl;
        std::cout << "*******************************" << std::endl;
	std::cout << "(1): Move a task into a tasklist" << std::endl;
        std::cout << "(2): Change a task name" << std::endl;
	std::cout << "(3): Change a task description" << std::endl;
	std::cout << "(4): Change a task type" << std::endl;
	std::cout << "(5): Change a task priority" << std::endl;
	std::cout << "(6): Change a task due date" << std::endl;
}

void printSortMenu(){
	std::cout << "*******************************" << std::endl;
        std::cout << "********** Sort Menu **********" << std::endl;
        std::cout << "*******************************" << std::endl;	
	std::cout << "(1): Sort by due date" << std::endl;
        std::cout << "(2): Sort by priority" << std::endl;
}

Task* getTaskFromUser(){
	std::string taskName,taskDescription,taskType,priority;
        Date dueDate;
        std::cout << "Task Name: ";
	std::getline(std::cin >> std::ws, taskName);

       // std::cout << std::endl;
        std::cout << "Description: ";
	std::getline(std::cin >> std::ws, taskDescription);
        
	//std::cout << std::endl;
        std::cout << "Type of task: " ;
	std::getline(std::cin >> std::ws, taskType);

	// std::cout << std::endl;
        std::cout << "Priority of Task (1-10): " ;
        std::cin >> priority;
	while (priority.length() > 2 ||(priority.length() > 0 && !std::isdigit(priority[0])) || (priority.length() == 2 && !std::isdigit(priority[1])) || stoi(priority) < 1 || stoi(priority) > 10){
		std::cout << "Invalid priority. Please re-enter the priority." << std::endl;
		std::cout << "Priority of Task (1-10): " ;
	        std::cin >> priority;
	}

        //std::cout << std::endl;
        std::cout << "Due Date (mm/dd/yyyy): " ;
        std::cin >> dueDate;
       // std::cout << std::endl;
	return new Task(taskName,taskDescription,taskType,stoi(priority),dueDate);	
	
}

TaskList* getTaskListFromUser(){
        std::string taskName,taskDescription,taskType, priority;
        Date dueDate;
        std::cout << "Task Name: " ;
        std::getline(std::cin >> std::ws, taskName);

 //       std::cout << std::endl;
        std::cout << "Description: " ;
        std::getline(std::cin >> std::ws, taskDescription);

   //     std::cout << std::endl;
        std::cout << "Type of task: " ;
        std::getline(std::cin >> std::ws, taskType);

     //   std::cout << std::endl;
        std::cout << "Priority of Task (1-10): " ;
        std::cin >> priority;
	while (priority.length() > 2 ||(priority.length() > 0 && !std::isdigit(priority[0])) || (priority.length() == 2 && !std::isdigit(priority[1])) || stoi(priority) < 1 || stoi(priority) > 10){
		std::cout << "Invalid priority. Please re-enter the priority." << std::endl;
		std::cout << "Priority of Task (1-10): " ;
	        std::cin >> priority;
	}

       // std::cout << std::endl;
        std::cout << "Due Date (mm/dd/yyyy): " ;
        std::cin >> dueDate;
        //std::cout << std::endl;
        char answer;
	std::cout << "Would you like to add any subtasks into your tasklist?(Y/N) " << std::endl;
	std::cin >> answer;
	while(toupper(answer) != 'Y' && toupper(answer) != 'N'){
		std::cout << "Invalid answer. Please re-enter your answer. (Y/N)" << std::endl;
		std::cin >> answer;
	}
	if(toupper(answer) == 'N')
	        return new TaskList(taskName,taskDescription,taskType, stoi(priority), dueDate);
	TaskList* tempTaskList =  new TaskList(taskName,taskDescription,taskType, stoi(priority), dueDate);
	tempTaskList->addTask(getTaskFromUser());

	do{
		std::cout << "Would you like to add any more subtasks into your tasklist?(Y/N) " << std::endl;
	        std::cin >> answer;
		while(toupper(answer) != 'Y' && toupper(answer) != 'N'){
        	        std::cout << "Invalid answer. Please re-enter your answer. (Y/N)" << std::endl;
                	std::cin >> answer;
	        }
		if(toupper(answer) == 'N')
	                return tempTaskList;
		
		tempTaskList->addTask(getTaskFromUser());
	}while(toupper(answer) != 'N');
	
	return tempTaskList;
}
/*
bool validDateFormat(std::string date){
        if(date.length() != 10)
                return false;
        std::string month = date.substr(0,2);
        std::string day = date.substr(3,2);
        std::string year = date.substr(6);

        for(int i = 0; i < month.length();i++){
                if(!isdigit(month[i]))
                        return false;
        }
        for(int i = 0; i < day.length();i++){
                if(!isdigit(day[i]))
                        return false;
        }
        for(int i = 0; i < year.length();i++){
                if(!isdigit(year[i]))
                        return false;
        }
        if(stoi(month) > 12 && stoi(month) < 1) //checking month
                return false;
        if(stoi(month) == 2 && stoi(day) > 28)   //checking days greater than 2/28
                return false;
        if((stoi(month) ==  1 || stoi(month) ==  3 || stoi(month) ==  5 || stoi(month) ==  7 ||
                                        stoi(month) ==  8 || stoi(month) ==  10 || stoi(month) ==  12)
                                        && stoi(day) > 31){   //checking for months with 31 days
                return false;
        }
        if((stoi(month) ==  4 || stoi(month) ==  6 || stoi(month) ==  9 || stoi(month) ==  11)
                                        && stoi(day) > 30){   //checking for months with 30 days
                return false;
        }

        if(stoi(day) < 1)       // false if day < 1
                return false;
        if(stoi(year) < 0)     //false if year < 0
                return false;
        return true;

}
*/

#endif
