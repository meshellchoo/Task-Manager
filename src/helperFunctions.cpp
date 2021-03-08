#ifndef __HELPERFUNCTIONS_CPP__
#define __HELPERFUNCTIONS_CPP__
#include <iostream>
#include <string>
//#include "/home/csmajs/mchu017/cs100-task-manager/header/helperFunctions.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/helperFunctions.hpp"

void printMenu(){
	std::cout << "********** Main Menu **********" << std::endl;
	std::cout << "(1): Create a new task" << std::endl;
	std::cout << "(2): Create a new tasklist" << std::endl;
	std::cout << "(3): Delete a task/tasklist" << std::endl;
	std::cout << "(4): Display schedule of tasks" << std::endl;
	std::cout << "(5): Delete a task/taskList" << std::endl;
  	std::cout << "(6): Sort schedule by due date" << std::endl;
	std::cout << "(7): Sort schedule by priority" << std::endl;
	std::cout << "(8): Sort schedule by type of task" << std::endl;
}


#endif
