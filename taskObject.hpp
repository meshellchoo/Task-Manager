#ifndef __TASKOBJECT_HPP__
#define __TASKOBJECT_HPP__

#include <string>

class TaskObject {

    protected:
	std::string taskName;
	std::string description;
	std::string taskType;
	int priority;
	std::string dueDate;

    public:
        /* Constructors */
        TaskObject() { }
	TaskObject(std::string taskName, std::string description, std::string taskType,
		 int priority,std::string  dueDate) {}
        virtual ~TaskObject() {}
    
        /* Pure Virtual Functions */
	virtual void viewTask() = 0;
	virtual void setTaskName() = 0;
	virtual void setTaskType() = 0;
	virtual void setTaskDescription() = 0;
        virtual void setTaskPriority() = 0;
	virtual void setTaskDueDate() = 0;
        virtual void getTaskName() = 0;
        virtual void getTaskType() = 0;
        virtual void getTaskDescription() = 0;
	virtual void getTaskPriority() = 0;
        virtual void getTaskDueDate() =0;

	virtual TaskObject* createTaskMemento() = 0;
	virtual void restore(TaskMemento) = 0;
};

#endif //__TASKOBJECT_HPP__
