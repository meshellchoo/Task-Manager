#ifndef __TASKMANAGER_HPP__
#define __TASKMANAGER_HPP__

#include "TaskBank.hpp"
#include "helperFunctions.hpp"
#include "TaskBankCommand.hpp"
class TaskManager {

    private:
	TaskBank* taskBank;
	TaskBankCommand* taskBankCommand;
    public:
	TaskManager();
	~TaskManager();
	void run();

};
#endif //__TASKMANAGER_HPP__
