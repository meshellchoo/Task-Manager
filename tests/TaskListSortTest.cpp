#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
#include <iostream>

int main(){

    std::cout << "=============================================================" << std::endl;
    std::cout << "After adding six Tasks " << std::endl;
    std::cout << "=============================================================" << std::endl;
    Task t1("CS100 Lab5", "Strategy and Composite Lab", "School",4,Date("02/21/2021"));
    Task t2("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,Date("02/27/2021"));
    Task t3("CS100 Lab7", "Visitor Design Pattern Lab", "School" ,2,Date("03/01/2021"));
    Task t4("CS100 Lab8", "final Lab", "School" ,1,Date("03/10/2021"));
    Task t5("CS100 Lab4", "___  Lab", "School" ,5,Date("03/10/2021"));
    Task t6("CS100 Lab3", "___  Lab", "School" ,2,Date("03/10/2021"));
    Task t7("CS100 Lab2", "___s  Lab", "School" ,2,Date("03/11/2021"));
    
    TaskList taskList("CS100 Labs","Labs for CS100", "School" ,2,Date( "02/27/2021" ));
    taskList.addTask(t7);
    taskList.addTask(t6);
    taskList.addTask(t5);
    taskList.addTask(t4);
    taskList.addTask(t3);
    taskList.addTask(t2);
    taskList.addTask(t1);
    taskList.viewTask();
    taskList.sortByPriority();
    //taskList.sortByDueDate();

    std::cout << "=============================================================" << std::endl;
    std::cout << "After sorting TaskList " << std::endl;
    std::cout << "=============================================================" << std::endl;
    taskList.viewTask();



    /*
 *     std::cout << "=============================================================" << std::endl;
 *         std::cout << "After deleting the CS100 Lab5 Task" << std::endl;
 *             std::cout << "=============================================================" << std::endl;
 *                 taskList.deleteTask(t);
 *                     taskList.viewTask();
 *   */
}
