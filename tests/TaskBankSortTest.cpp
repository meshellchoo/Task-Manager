#include "../header/TaskBank.hpp"


#include <iostream>

int main()
{
	std::cout << "======================" << std::endl;
	std::cout << "After adding four Tasks" << std::endl;
	std::cout << "======================" << std::endl;
	Task t1("CS100 Lab 1", "Introduction to Software Construction Tooling", "School", 3, Date("01/21/2021"));
	Task t2("CS100 Lab 2", "Github Flow", 4, Date("01/28/2021"));
	Task t3("ENGR 108 Essay", "First Term Paper", 5, Date("01/31/2021"));
	Task t4("ENGR 101I Assignment 1", "Google Drive Survey", 7, Date("02/02/2021"));
 	TaskBank taskBank;
	taskBank.addTask(t1);
	taskBank.addTask(t2);
	taskBank.addTask(t3);
	taskBank.addTask(t4);
	taskBank.viewTask();
	taskBank.sortByPriority();
	taskBanks.sortByDueDate();
std::cout << "========================" << std::endl;
std::cout << "After sorting TaskList" << std::endl;
std::cout << "========================" << std::endl;
	
}	
