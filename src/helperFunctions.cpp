#ifndef __HELPERFUNCTIONS_CPP__
#define __HELPERFUNCTIONS_CPP__
#include <iostream>
#include <string>
#include "/home/csmajs/mchu017/cs100-task-manager/header/helperFunctions.hpp"
//#include "/home/csmajs/jooi001/cs100-task-manager/header/helperFunctions.hpp"

void printMenu(){
	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "(1): Add a task" << std::endl;
	std::cout << "(2): Add a tasklist" << std::endl;
	std::cout << "(3): Edit task" << std::endl;
	std::cout << "(4): Delete task" << std::endl;
	std::cout << "(4): Display all tasks" << std::endl;
//  	std::cout << "(6): Sort schedule by due date" << std::endl;
//	std::cout << "(7): Sort schedule by priority" << std::endl;
//	std::cout << "(8): Sort schedule by type of task" << std::endl;
	
}

Task* getTaskFromUser(){
	std::string taskName,taskDescription,taskType;
	int priority;
        Date dueDate;
        std::cout << "Task Name: " ;
        std::cin >> taskName;
        std::cout << std::endl;
        std::cout << "Description: " ;
        std::cin >> taskDescription;
        std::cout << std::endl;
        std::cout << "Type of task: " ;
        std::cin >> taskType;
        std::cout << std::endl;
        std::cout << "Priority of Task (1-5): " ;
        std::cin >> priority;
        std::cout << std::endl;
        std::cout << "Due Date (mm/dd/yy): " ;
        std::cin >> dueDate;
        std::cout << std::endl;
	
        return new Task(taskName,taskDescription,taskType,priority,dueDate);
}

TaskList* getTaskListFromUser(){
        std::string taskName,taskDescription,taskType;
        int priority;
        Date dueDate;
        std::cout << "Task Name: " ;
        std::cin >> taskName;
        std::cout << std::endl;
        std::cout << "Description: " ;
        std::cin >> taskDescription;
        std::cout << std::endl;
        std::cout << "Type of task: " ;
        std::cin >> taskType;
        std::cout << std::endl;
        std::cout << "Priority of Task (1-5): " ;
        std::cin >> priority;
        std::cout << std::endl;
        std::cout << "Due Date (mm/dd/yy): " ;
        std::cin >> dueDate;
        std::cout << std::endl;

        return new TaskList(taskName,taskDescription,taskType,priority, dueDate);
}


#endif
