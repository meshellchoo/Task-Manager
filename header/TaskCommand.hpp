#include "TaskMemento.hpp"
#include <vector>

class TaskCommand{
private:
	vector<TaskMemento> savedTasks = new vector<TaskMemento>();

public:
	void addTaskMemento(TaskMemento tm);
	TaskMemento getTaskMemento(int index);

};
