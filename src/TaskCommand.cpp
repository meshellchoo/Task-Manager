#include "TaskCommand.hpp"
#include <vector>

void TaskCommand::addTaskMemento(TaskMemento tm){
	savedTasks.push_back(tm);
}


TaskMemento TaskCommand::getTaskMemento(int index){
	return savedTasks.at(index);	


}
