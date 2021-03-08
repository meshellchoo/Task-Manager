#include "TaskMemento.hpp"
#include <vector>

class TaskCommand{
private:
	std::vector<TaskMemento> savedTasks;

public:
	void addTaskMemento(TaskMemento tm);
	TaskMemento getTaskMemento(int index);

};
