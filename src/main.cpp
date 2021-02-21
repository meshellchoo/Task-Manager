//#include "/home/csmajs/jooi001/cs100-task-manager/src/TaskList.cpp" // change to your branch directory
//#include "/home/csmajs/jooi001/cs100-task-manager/src/Task.cpp"

#include "/home/csmajs/mchu017/cs100-task-manager/src/TaskList.cpp" // change to your branch directory
#include "/home/csmajs/mchu017/cs100-task-manager/src/Task.cpp"

//#include "/home/csmajs/htran164/cs100-task-manager/src/TaskList.cpp" // change to your branch directory
//#include "/home/csmajs/htran164/cs100-task-manager/src/Task.cpp"

#include <iostream>

int main(int argv, char** argc) {
    Task t("CS100 Lab5", "Strategy and Composite Lab", "School",1,"02/21/2021");
    Task t2("CS100 Lab6", "Factory Design Pattern Lab", "School" ,2,"02/27/2021");
    TaskList taskList("CS100 Labs","Labs for CS100", "School" ,2, "02/27/2021" );
    taskList.addTask(t);
    taskList.addTask(t2);
    taskList.viewTask();
}
