#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskCommand.hpp"

void TaskCommand::addTaskMemento(TaskMemento tm){
	savedTasks.push_back(tm);
}


TaskMemento TaskCommand::getTaskMemento(int index){
	return savedTasks.at(index);	


}
