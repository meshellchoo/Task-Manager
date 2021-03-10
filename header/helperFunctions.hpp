#ifndef __HELPERFUNCTIONS_HPP__
#define __HELPERFUNCTIONS_HPP__
#include "TaskList.hpp"
//#include "TaskObject.hpp"
#include "Task.hpp"
#include "TaskBank.hpp"
void printMenu();
void printEditMenu();
void printSortMenu();
void printDeleteMenu();
Task* getTaskFromUser();
TaskList* getTaskListFromUser(TaskBank* taskBank);
//bool validDateFormat();

#endif
