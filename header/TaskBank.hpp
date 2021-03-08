#ifndef __TASKBANK_HPP__
#define __TASKBANK_HPP__
#include <vector>
#include "TaskObject.hpp"
#include "Task.hpp"
#include "TaskList.hpp"

class TaskBank{
	private:
		std::vector<TaskObject*> schedule;
	public:
		TaskBank(){};
		~TaskBank(){};
		void clear();
		void display();
		void addTask(TaskObject* task);
		bool deleteTask(TaskObject* task);
		void sortByPriority();
		void sortByDueDate();

		
void setTaskState(TaskBank newTaskBank);
TaskBankMemento storeInTaskBankMemento();
TaskBank restoreFromTaskBankMemento(TaskBankMemento taskBankMemento);

		TaskBank& operator=(const TaskBank& taskbank);
};

#endif
