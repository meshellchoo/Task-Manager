class TaskObject{
    protected:
        std::string taskName;
        std::string description;
        std::string taskType;
        int priority;
        std::string dueDate;
        
    public:
        virtual void viewTask() = 0;
        void setTaskName(std::string taskName){this->taskName = taskName;};
        void setTaskType(std::string taskType){this->taskType = taskType;};
        void setTaskDescription( std::string description){this->description = description;};
        std::string getTaskType(){return taskType;};
        std::string getTaskDescription(){return description;};
        int getTaskPriority(){return priority;};
        std::string getTaskDueDate(){return dueDate;};
        //TaskObject* createTaskMemento();
        //void restore(TaskMemento task);

}
