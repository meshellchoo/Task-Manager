#ifndef __TASKMANAGER_HPP__
#define __TASKMANAGER_HPP__

#include "TaskBank.hpp"
#include "helperFunctions.hpp"

class TaskManager {

    private:
	TaskBank schedule;
    public:
	TaskManager();
	void run();

};
#endif //__TASKMANAGER_HPP__
