#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskCommand.hpp"

//#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp"
//include "/home/csmajs/jooi001/cs100-task-manager/header/TaskCommand.hpp"

//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp"
//include "/home/csmajs/htran164/cs100-task-manager/header/TaskCommand.hpp"


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
    t1->setTaskState(t1);
    t2->setTaskState(t2);
    t3->setTaskState(t3);
    t4->setTaskState(t4);
    t5->setTaskState(t5);
    t6->setTaskState(t6);
    t7->setTaskState(t7);


    TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2, Date( "02/27/2021" ));
    taskList->addTask(t7);
    taskList->addTask(t6);
    taskList->addTask(t5);
    taskList->addTask(t4);
    taskList->addTask(t3);
    taskList->addTask(t2);
    taskList->addTask(t1);
    taskList->viewTask();
    taskList->sortByPriority();
    taskList->setTaskState(taskList);
    //taskList.sortByDueDate();

    std::cout << "=============================================================" << std::endl;
    std::cout << "After sorting TaskList " << std::endl;
    std::cout << "=============================================================" << std::endl;
    taskList->viewTask();






    std::cout << "=============================================================" << std::endl;
    std::cout << "Editing TaskList Description " << std::endl;
    std::cout << "=============================================================" << std::endl;

    /*
 *     std::cout << "=============================================================" << std::endl;
 *         std::cout << "After deleting the CS100 Lab5 Task" << std::endl;
 *             std::cout << "=============================================================" << std::endl;
 *                 taskList.deleteTask(t);
 *                     taskList.viewTask();
 *   */
}
