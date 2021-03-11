#ifndef __TASKBANKCOMMAND_CPP__
#define __TASKBANKCOMMAND_CPP__

//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankCommand.hpp" 

//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskBankCommand.hpp"

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankCommand.hpp"


TaskBankCommand::TaskBankCommand(TaskBank *taskBank){
    this->_taskBank = taskBank;
}
void TaskBankCommand::Backup() {
    this->_mementos.push_back(this->_taskBank->createTaskBankMemento());
}
void TaskBankCommand::Undo() {
    if (!this->_mementos.size()) {
      return;
    }

    TaskBankMemento* memento = this->_mementos.back();
    this->_mementos.pop_back();
   	 
     //std::cout << "Caretaker: Restoring state  "; // << memento->GetName() << "\n";
    try {
      this->_taskBank->restore(memento);
    } catch (...) {
      this->Undo();
    }
    
}

TaskBankCommand::~TaskBankCommand(){
	for(int i = 0 ; i < _mementos.size();i ++){
		delete _mementos[i];
		_mementos[i] = nullptr;
	}
	_mementos.clear();
	delete _taskBank;
}



#endif



