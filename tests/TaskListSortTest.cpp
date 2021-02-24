#include "header/TaskList.hpp"

//NOT FINISHED 

    std::cout << "=============================================================" << std::endl;
    std::cout << "After adding four Tasks " << std::endl;
    std::cout << "=============================================================" << std::endl;
    Task t1("CS100 Lab5", "Strategy and Composite Lab", "School",4,"02/21/2021");
    Task t2("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,"02/27/2021");
    Task t3("CS100 Lab7", "Visitor Design Pattern Lab", "School" ,2,"03/01/2021");
    Task t4("CS100 Lab8", "final Lab", "School" ,1,"03/10/2021");
    TaskList taskList("CS100 Labs","Labs for CS100", "School" ,2, "02/27/2021" );
    taskList.addTask(t4);
    taskList.addTask(t3);
    taskList.addTask(t2);
    taskList.addTask(t1);
    taskList.viewTask();
    TaskList prioritySortedTaskList = taskList.sortByPriority();
    std::cout << "=============================================================" << std::endl;
    std::cout << "After sorting TaskList " << std::endl;
    std::cout << "=============================================================" << std::endl;
    prioritySortedTaskList.viewTask();



    /*
 *     std::cout << "=============================================================" << std::endl;
 *         std::cout << "After deleting the CS100 Lab5 Task" << std::endl;
 *             std::cout << "=============================================================" << std::endl;
 *                 taskList.deleteTask(t);
 *                     taskList.viewTask();
 *   */

