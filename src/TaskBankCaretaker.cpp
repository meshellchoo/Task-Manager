#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankCaretaker.hpp"

void TaskBankCaretaker::addTaskBankMemento(TaskBankMemento tbm){
	savedTaskBanks.push_back(tbm);
}


TaskBankMemento TaskBankCaretaker::getTaskBankMemento(int index){
	return savedTaskBanks.at(index);	


}
