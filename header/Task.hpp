#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "TaskObject.hpp"
class Task: public TaskObject{

    private:
 
    public:
        Task();
	Task(std::string taskName, std::string description, std::string taskType,
		 int priority, Date dueDate);
	void viewTask();
	
	virtual void setTaskState(Task newTask){
                std::cout << "From Originator: Current Version of Task\n" <<  newTask.getName() << std::endl;
                task = newTask;
        }

        virtual TaskMemento storeInMemento(){
                std::cout << "From Originator: Saving to Memento" << std::endl;
                return new TaskMemento(task);
        }

        virtual void restoreFromTaskMemento(TaskMemento taskMemento){
                task = taskMemento.getSavedTask();
                std::cout << "From Originator: Previous Task Saved Memento\n" << task.getName() << std::endl;
                return task;
        }
};

#endif //__TASK_HPP__

