
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp" // change to your branch directory
#include "/home/csmajs/jooi001/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/helperFunctions.hpp"

/*
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp" // change to your branch directory
#include "/home/csmajs/mchu017/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"
//#include "/home/csmajs/mchu017/cs100-task-manager/header/helperFunctions.hpp"
//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankMemento.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankCommand.hpp"
*/
//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp" // change to your branch directory
//#include "/home/csmajs/htran164/cs100-task-manager/header/Task.hpp"
//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"

#include <iostream>

int main(int argv, char** argc) {

    	std::cout << "=============================================================" << std::endl;
 //   	std::cout << "After adding six Tasks " << std::endl;
    	std::cout << "=============================================================" << std::endl;
   	//Task* t1 = new Task("CS100 Lab5", "Strategy and Composite Lab", "School",4,Date("02/21/2021"));
    	Task* t2 = new Task("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,Date("02/27/2021"));
    	Task* t3 = new Task("CS100 Lab7", "Visitor Design Pattern Lab", "School" ,2,Date("03/01/2021"));
    	Task* t4 = new Task("CS100 Lab8", "final Lab", "School" ,1,Date("03/10/2021"));



    	Task t5 = Task("CS100 Lab4", "___  Lab", "School" ,5,Date("03/10/2021"));
    	Task t6 = Task("CS100 Lab3", "___  Lab", "School" ,2,Date("03/10/2021"));
	Task t7 = Task("CS100 Lab2", "___s  Lab", "School" ,2,Date("03/11/2021"));

	TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2, Date( "02/27/2021" ));
    	taskList->addTask(t7);
	taskList->addTask(t6);
	taskList->addTask(t5);	

	TaskBank* taskBank = new TaskBank();

	TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);

	
	taskBank->addTask(taskList);
	taskBankCommand->Backup();
	taskBank->addTask(t4);
	taskBankCommand->Backup();
	taskBank->addTask(t3);
	taskBankCommand->Backup();
	taskBank->addTask(t2);
	taskBankCommand->Backup();

	
	std::cout << "=============================================================" << std::endl;
	std::cout << "before undo" << std::endl;
	std::cout << "=============================================================" << std::endl;
	taskBank->display();
	
	taskBankCommand->Undo();
	taskBankCommand->Undo();
	taskBankCommand->Undo();
	
	std::cout << "=============================================================" << std::endl;
	std::cout << "after undo 3 times" << std::endl;
	std::cout << "=============================================================" << std::endl;
	taskBank->display();

	taskBankCommand->Undo();
	std::cout << "=============================================================" << std::endl;
        std::cout << "after 4th undo" << std::endl;
	std::cout << "=============================================================" << std::endl;
        taskBank->display();	

	taskBankCommand->Undo();
        std::cout << "=============================================================" << std::endl;
        std::cout << "after 5th undo" << std::endl;
        std::cout << "=============================================================" << std::endl;
        taskBank->display();		
	
	taskBankCommand->Undo();
        std::cout << "=============================================================" << std::endl;
        std::cout << "after 6th undo" << std::endl;
        std::cout << "=============================================================" << std::endl;
        taskBank->display();

	taskBank->addTask(new Task("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,Date("02/27/2021")));
	taskBankCommand->Undo();
        std::cout << "=============================================================" << std::endl;
        std::cout << "after adding a task and 7th undo" << std::endl;
        std::cout << "=============================================================" << std::endl;
        taskBank->display();	
	
	delete taskBankCommand;

//	delete taskBank;
	//delete taskList;
}

