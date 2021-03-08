#include "TaskBankMemento.hpp"
#include <vector>

class TaskBankCaretaker{
private:
	std::vector<TaskBankMemento> savedTaskBanks;

public:
	void addTaskBankMemento(TaskBankMemento tbm);
	TaskBankMemento getTaskBankMemento(int index);

};
