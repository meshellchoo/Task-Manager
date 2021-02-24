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
		~TaskBank(){};
		void clear();
		void display();
		void addTask(TaskObject*);
		void deleteTask(TaskObject*);
		void sortByPriority();
//		TaskObject* createTaskBankMemento();
//		void restore(taskBankMemento);

}

#endif
