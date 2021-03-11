#ifndef __TASK_HPP__
#define __TASK_HPP__

class Task: public TaskObject{

    private:
 
    public:
        Task();
	Task(std::string taskName, std::string description, std::string taskType,
		 int priority, Date dueDate);
	void viewTask();

	void setTaskState(TaskObject* newTask);

        bool isTaskList();
};

#endif //__TASK_HPP__
