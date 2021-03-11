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
bool stringIsInt(std::string checkThis);
Task* getTaskFromUser();
TaskList* getTaskListFromUser(TaskBank* taskBank);
bool stringIsInt(std::string checkThis);
//bool validDateFormat();

#endif
