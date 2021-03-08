//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp"
//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskCommand.hpp"


#include <iostream>

int main(){

    std::cout << "=============================================================" << std::endl;
    std::cout << "After adding six Tasks " << std::endl;
    std::cout << "=============================================================" << std::endl;
    TaskObject* t1 = new Task("CS100 Lab5", "Strategy and Composite Lab", "School",4,Date("02/21/2021"));
    TaskObject* t2 = new Task("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,Date("02/27/2021"));
    TaskObject* t3 = new Task("CS100 Lab7", "Visitor Design Pattern Lab", "School" ,2,Date("03/01/2021"));
    TaskObject* t4 = new Task("CS100 Lab8", "final Lab", "School" ,1,Date("03/10/2021"));
    TaskObject* t5 = new Task("CS100 Lab4", "___  Lab", "School" ,5,Date("03/10/2021"));
    TaskObject* t6 = new Task("CS100 Lab3", "___  Lab", "School" ,2,Date("03/10/2021"));
    TaskObject* t7 = new Task("CS100 Lab2", "___s  Lab", "School" ,2,Date("03/11/2021"));

    TaskCommand* taskListCommand = new TaskCommand; // create task command to keep track of task list mementos
    int saveFiles = 0;
    int currentTaskList = 0;

    TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2, Date( "02/27/2021" ));
    taskList->addTask(t7);
    taskList->addTask(t6);
    taskList->addTask(t5);
    taskList->addTask(t4);
    taskList->addTask(t3);
    taskList->addTask(t2);
    taskList->addTask(t1);
    taskList->viewTask();
    taskList->setTaskState(taskList); //set current state
    taskListCommand->addTaskMemento(taskList->storeInMemento()); //save current state in memento
    saveFiles++;
    currentTaskList++;


    taskList->sortByPriority();
    //taskList.sortByDueDate();

    std::cout << "=============================================================" << std::endl;
    std::cout << "After sorting TaskList " << std::endl;
    std::cout << "=============================================================" << std::endl;
    taskList->viewTask();
    taskList->setTaskState(taskList); //set current state
    taskListCommand->addTaskMemento(taskList->storeInMemento()); //save current state in memento
    saveFiles++;
    currentTaskList++;

    std::cout << "=============================================================" << std::endl;
    std::cout << "Editing TaskList Description " << std::endl;
    std::cout << "=============================================================" << std::endl;
    taskList->setTaskDescription("check out this new description");
    taskList->viewTask();
    taskList->setTaskState(taskList); //set current state
    taskListCommand->addTaskMemento(taskList->storeInMemento()); //save current state in memento
    saveFiles++;
    currentTaskList++;

    std::cout << "=============================================================" << std::endl;
    std::cout << "Restoring Previous TaskList Description " << std::endl;
    std::cout << "=============================================================" << std::endl;
    if (currentTaskList >= 1){
	currentTaskList--;	
	TaskObject* previousTaskList = taskList->restoreFromTaskMemento(taskListCommand->getTaskMemento(currentTaskList));
	taskList->setTaskState(previousTaskList->getSavedState());
}    

    taskList->viewTask();

    /*
 *     std::cout << "=============================================================" << std::endl;
 *         std::cout << "After deleting the CS100 Lab5 Task" << std::endl;
 *             std::cout << "=============================================================" << std::endl;
 *                 taskList.deleteTask(t);
 *                     taskList.viewTask();
 *   */
}
