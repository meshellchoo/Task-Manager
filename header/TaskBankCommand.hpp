#ifndef __TASKBANKCOMMAND_HPP__
#define __TASKBANKCOMMAND_HPP__
#include "TaskBank.hpp"
#include "TaskBankMemento.hpp"
class TaskBankCommand{
private:
	std::vector<TaskBankMemento*> _mementos;
	TaskBank* _taskBank;

public:
	TaskBankCommand(TaskBank *taskBank);
	void Backup();
	void Undo();

};





#endif
