/*
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp" // change to your branch directory
#include "/home/csmajs/jooi001/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankCommand.hpp"
*/

/*
#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/htran164/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/htran164/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/htran164/cs100-task-manager/header/TaskBankCommand.hpp"
*/

#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankCommand.hpp"

#include <iostream>

int main(int argv, char** argc) {
	std::cout << "=============================================================" << std::endl;
    	std::cout << "Creating 6 Tasks and 1 Task List" << std::endl;
 	std::cout << "=============================================================" << std::endl;
	Task* t2 = new Task("CS100 Lab6", "Factory Design Pattern Lab", "School" ,3,Date("02/27/2021"));
    	Task* t3 = new Task("CS100 Lab7.6", "Visitor Design Pattern Lab", "School" ,2,Date("03/01/2021"));
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

	taskBank->display();

        std::cout << "=============================================================" << std::endl;
        std::cout << "Searching TaskBank for '6'" << std::endl;
        std::cout << "=============================================================" << std::endl;
	std::vector<TaskObject*> found = taskBank->search("6");
	if (found.size() > 0){
               for (int i = 0; i < found.size(); i++){
                        found[i]->viewTask();
                }
        }
       
	else {
                std::cout << "No Tasks/TaskLists were found." << std::endl;
        }



        std::cout << "=============================================================" << std::endl;
        std::cout << "Searching TaskBank for 'OOF'" << std::endl;
        std::cout << "=============================================================" << std::endl;
        found = taskBank->search("OOF");
	if (found.size() > 0){
                for (int i = 0; i < found.size(); i++){
                        found[i]->viewTask();
                }
	}
	else {
		std::cout << "No Tasks/TaskLists were found." << std::endl;
	}

	delete taskBankCommand;
}

