#ifndef _UNIT_TEST_
#define _UNIT_TEST_

#include "gtest/gtest.h"

/*
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBank.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankCommand.hpp"
*/

/*
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/Task.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskBankMemento.hpp"
#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskObject.hpp"
*/

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBank.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankCommand.hpp"

/*
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBank.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankCommand.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskBankMemento.hpp"
*/
/*
#include "/home/csmajs/cs100/htran164/cs100-task-manager/header/TaskBank.hpp"
#include "/home/csmajs/cs100/htran164/cs100-task-manager/header/TaskBankCommand.hpp"
#include "/home/csmajs/cs100/htran164/cs100-task-manager/header/TaskManager.hpp"
#include "/home/csmajs/cs100/htran164/cs100-task-manager/header/TaskBankMemento.hpp"
*/
int main (int argc, char** argv){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}


TEST(TaskTest, setNewTaskName)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
	t1->setTaskName("Updated Task 1");
        EXPECT_EQ("Updated Task 1", t1->getTaskName());
        delete t1;
}


TEST(TaskTest, setNewTaskDescription)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
	t1->setTaskDescription("This is my updated first task");
        EXPECT_EQ("This is my updated first task", t1->getTaskDescription());
        delete t1;
}

TEST(TaskTest, setNewTaskType)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        EXPECT_EQ("New Test", t1->getTaskType());
        delete t1;
}

TEST(TaskTest, setNewTaskPriority)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
	t1->setTaskPriority(3);
        EXPECT_EQ(3, t1->getTaskPriority());
        delete t1;
}

TEST(TaskTest, setTaskDueDate)  // make test to handle due date
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
	t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021"), t1->getTaskDueDate());
        delete t1;

}

TEST(TaskTest, getUpdatedTaskName)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
        t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("Updated Task 1" , t1->getTaskName());
        delete t1;
}

TEST(TaskTest, getUpdatedTaskDescription)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
        t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("This is my updated first task" , t1->getTaskDescription());
        delete t1;
}

TEST(TaskTest, getUpdatedTaskType)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
        t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("New Test" , t1->getTaskType());
        delete t1;
}

TEST(TaskTest, getUpdatedTaskPriority)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
        t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(3 , t1->getTaskPriority());
        delete t1;
}

TEST(TaskTest, getUpdatedTaskDueDate)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1->setTaskName("Updated Task 1");
        t1->setTaskDescription("This is my updated first task");
        t1->setTaskType("New Test");
        t1->setTaskPriority(3);
        t1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021") , t1->getTaskDueDate());
        delete t1;
}

TEST(TaskTest, viewTask)
{
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 3, Date("03/11/2021"));
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 3, Date("03/11/2021"));

        std::stringstream s;
        std::stringstream output;

        t1->viewTask(s);
        _t1->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete t1;
        delete _t1;
}

TEST(TaskListTest, setNewTaskListName)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
	EXPECT_EQ("Updated CS100 Labs" , taskList1->getTaskName());
        delete taskList1;
}

TEST(TaskListTest, setNewTaskListDescription)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
	EXPECT_EQ("Updated Labs for CS100", taskList1->getTaskDescription());
        delete taskList1;
}

TEST(TaskListTest, setNewTaskListType)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
	taskList1->setTaskType("New School");
        EXPECT_EQ("New School", taskList1->getTaskType());
        delete taskList1;
}

TEST(TaskListTest, setNewTaskListPriority)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" , 2, Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
	taskList1->setTaskPriority(5);
	EXPECT_EQ(5, taskList1->getTaskPriority());
        delete taskList1;
}

TEST(TaskListTest, setNewTaskListDueDate)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
	taskList1->setTaskType("New School");
	taskList1->setTaskPriority(5);
 	taskList1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021"), taskList1->getTaskDueDate());
        delete taskList1;
}

TEST(TaskListTest, getUpdatedTaskListName)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
	taskList1->setTaskType("New School");
	taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("Updated CS100 Labs", taskList1->getTaskName());
        delete taskList1;
}

TEST(TaskListTest, getUpdatedTaskListDescription)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
	EXPECT_EQ("Updated Labs for CS100", taskList1->getTaskDescription());
        delete taskList1;
}

TEST(TaskListTest, getUpdatedTaskListType)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("New School", taskList1->getTaskType());
        delete taskList1;
}

TEST(TaskListTest, getUpdatedTaskListPriority)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(5, taskList1->getTaskPriority());
        delete taskList1;
}

TEST(TaskListTest, addTask)
{
        TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        taskList->addTask(t2);

        TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        _taskList->addTask(_t2);

        std::stringstream s;
        std::stringstream output;

        taskList->viewTask(s);
        _taskList->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete taskList;
        delete _taskList;
}

TEST(TaskListTest, addMultipleTasks)
{
        TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList->addTask(t2);
        taskList->addTask(t3);

        TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        _taskList->addTask(_t2);
        _taskList->addTask(_t3);

        std::stringstream s;
        std::stringstream output;

        taskList->viewTask(s);
        _taskList->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete taskList;
        delete _taskList;
}

TEST(TaskListTest, addMultipleTasksThenDeleteOne)
{
        TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
	Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList->addTask(t1);
        taskList->addTask(t2);
	taskList->addTask(t3);
	taskList->deleteTask(t1);

        TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        _taskList->addTask(_t2);
        _taskList->addTask(_t3);

        std::stringstream s;
        std::stringstream output;

        taskList->viewTask(s);
        _taskList->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete taskList;
        delete _taskList;
}


TEST(TaskListTest, deleteTask)
{
        TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        taskList->addTask(t1);
        taskList->deleteTask(t1);

        TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));

        std::stringstream s;
        std::stringstream output;

        taskList->viewTask(s);
        _taskList->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete taskList;
        delete _taskList;
}


TEST(TaskListTest, deleteAlreadyDeletedTask)
{
        TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        taskList->addTask(t1);
	taskList->deleteTask(t1);
	taskList->deleteTask(t1);

        TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));

        std::stringstream s;
        std::stringstream output;

        taskList->viewTask(s);
        _taskList->viewTask(output);
        EXPECT_EQ(s.str(),output.str());

        delete taskList;
        delete _taskList;
}

TEST(TaskListTest, clearTaskList)
{
	TaskList* taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	
	taskList->addTask(t1);
	taskList->addTask(t2);
	taskList->addTask(t3);
	taskList->clear();

	TaskList* _taskList = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
	
	std::stringstream s;
	std::stringstream output;

	taskList->viewTask(s);
	_taskList->viewTask(output);
	EXPECT_EQ(s.str(),output.str());

	delete taskList;
	delete _taskList;
}



TEST(TaskListTest, sortByDueDate_TaskList)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1->addTask(t1);
        taskList1->addTask(t2);
        taskList1->addTask(t3);
        taskList1->sortByDueDate(); // print task 2, task 3, task 1

        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        TaskList* _taskList1 = new TaskList("Updated CS100","Updated Labs for CS100", "New School" , 5, Date("03/11/2021"));
        _taskList1->addTask(_t2);
        _taskList1->addTask(_t3);
        _taskList1->addTask(_t1);

        std::stringstream s;
        std::stringstream output;

        taskList1->viewTask(s);
        taskList1->viewTask(output);

        EXPECT_EQ(s.str(), output.str());

        delete taskList1;
        delete _taskList1;
}


TEST(TaskListTest, sortByPriority_TaskList)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1->addTask(t1);
        taskList1->addTask(t2);
        taskList1->addTask(t3);
	taskList1->sortByPriority(); // print task 1, task 3, task 2

        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        TaskList* _taskList1 = new TaskList("Updated CS100","Updated Labs for CS100", "New School" , 5, Date("03/11/2021"));
        _taskList1->addTask(_t1);
        _taskList1->addTask(_t3);
        _taskList1->addTask(_t2);

        std::stringstream s;
        std::stringstream output;

        taskList1->viewTask(s);
        taskList1->viewTask(output);

        EXPECT_EQ(s.str(), output.str());

        delete taskList1;
        delete _taskList1;
}


TEST(TaskListTest, viewTaskList)
{
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1->addTask(t1);
        taskList1->addTask(t2);
        taskList1->addTask(t3);

        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        TaskList* _taskList1 = new TaskList("Updated CS100","Updated Labs for CS100", "New School" , 5, Date("03/11/2021"));
        _taskList1->addTask(_t1);
        _taskList1->addTask(_t2);
        _taskList1->addTask(_t3);

        std::stringstream s;
        std::stringstream output;

        taskList1->viewTask(s);
        taskList1->viewTask(output);

        EXPECT_EQ(s.str(), output.str());

        delete taskList1;
        delete _taskList1;


}

TEST(TaskBankTest, addTask_TaskBank)
{
        TaskBank* taskBank = new TaskBank();
        Task* task = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        taskBank->addTask(task);
        Task* _task = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        TaskBank* _taskBank = new TaskBank();
        _taskBank->addTask(_task);

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);

        EXPECT_EQ(s.str(), output.str());

        delete taskBank;
        delete _taskBank;
}


TEST(TaskBankTest, addTaskList_TaskBank)
{
        TaskBank* taskBank = new TaskBank();
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        taskBank->addTask(taskList);
        TaskList* _taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        TaskBank* _taskBank = new TaskBank();
	_taskBank->addTask(_taskList);

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);

        EXPECT_EQ(s.str(), output.str());

        delete taskBank;
        delete _taskBank;	
}


TEST(TaskBankTest, deleteTask_TaskBank)
{
	TaskBank* taskBank = new TaskBank();
	TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        
        taskBank->addTask(taskList);
	taskBank->deleteTask(taskList);

	TaskBank* _taskBank = new TaskBank();

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);

        EXPECT_EQ(s.str(), output.str());
        
	delete taskBank;
        delete _taskBank;		
}

TEST(TaskBankTest, clearTaskBank)
{
	TaskBank* taskBank = new TaskBank();
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	
	taskBank->addTask(t1);
	taskBank->addTask(t2);
	taskBank->addTask(t3);
	taskBank->clear();

	TaskBank* taskBank1 = new TaskBank();
	
	std::stringstream s;
	std::stringstream output;

	taskBank1->display(s);
	taskBank->display(output);
	EXPECT_EQ(s.str(),output.str());
	delete taskBank1;
	delete taskBank;
}

TEST(TaskBankTest, searchTaskBankMichelle)
{
	TaskBank* taskBank = new TaskBank(); 
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	taskBank->addTask(t1);
	taskBank->addTask(t2);
	taskBank->addTask(t3);
	std::vector<TaskObject*>  found;
	found = taskBank->search(t2->getTaskName());
	EXPECT_EQ(t2, found[0]);
	
	for(int i = 1; i < found.size(); i++){
		delete found[i];
	}	
	delete taskBank;
}

TEST(TaskBankTest, searchNonExistingTaskTaskBank)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        taskBank->addTask(taskList);
        taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
        std::vector<TaskObject*> found = taskBank->search("doodoo");
        EXPECT_EQ(0, found.size());
        delete taskBank;
}


TEST(TaskBankTest, searchEmptyStringTaskBank)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        taskBank->addTask(taskList); 
        taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
        std::vector<TaskObject*> found = taskBank->search("");
        EXPECT_EQ(4, found.size());
        delete taskBank;
}


TEST(TaskBankTest, searchSubStrTaskBank)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
	taskBank->addTask(taskList);
	taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
        std::vector<TaskObject*> found = taskBank->search("ask");
        EXPECT_EQ(4, found.size());
        delete taskBank;
}

TEST(TaskBankTest, searchExistingTaskBank)
{
	TaskBank* taskBank = new TaskBank(); 
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        taskBank->addTask(taskList);
	taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
	std::vector<TaskObject*> found = taskBank->search(t1->getTaskName());
	EXPECT_EQ(1, found.size());
	delete taskBank;
}

TEST(TaskBankTest, display)
{
	TaskBank* taskBank = new TaskBank();
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	taskBank->addTask(t1);
	taskBank->addTask(t2);
	taskBank->addTask(t3);

        TaskBank* _taskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        _taskBank->addTask(_t1);
        _taskBank->addTask(_t2);
        _taskBank->addTask(_t3);


        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());

	delete taskBank;
	delete _taskBank;
}

TEST(TaskBankTest, undoTaskEdit)
{
        TaskBank* taskBank = new TaskBank();
        TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
        taskBankCommand->Backup();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));

        taskBank->addTask(t1);
        taskBankCommand->Backup();

        t1->setTaskName("This is my new task name.");
        taskBankCommand->Backup();

        taskBankCommand->Undo();
        taskBankCommand->Undo();

        TaskBank* _taskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        _taskBank->addTask(_t1);

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());

        delete _taskBank;
        delete taskBankCommand;
}


TEST(TaskBankTest, undoTaskListEdit)
{
        TaskBank* taskBank = new TaskBank();
        TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
        taskBankCommand->Backup();
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));

        taskBank->addTask(t1);
        taskBankCommand->Backup();
        taskBank->addTask(taskList);
        taskBankCommand->Backup();

	taskList->setTaskName("This is my new task name.");
	taskBankCommand->Backup();

        taskBankCommand->Undo();
        taskBankCommand->Undo();

        TaskBank* _taskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        _taskBank->addTask(_t1);
	TaskList* _taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
	_taskBank->addTask(_taskList);

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());

        delete _taskBank;
        delete taskBankCommand;
}

TEST(TaskBankTest, undoTaskListAddTaskList)
{
        TaskBank* taskBank = new TaskBank();
        TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
        taskBankCommand->Backup();
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));

        taskBank->addTask(t1);
        taskBankCommand->Backup();
        taskBank->addTask(taskList);
        taskBankCommand->Backup();

        taskBankCommand->Undo();
        taskBankCommand->Undo();

        TaskBank* _taskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        _taskBank->addTask(_t1);


        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());

        delete _taskBank;
        delete taskBankCommand;
}



TEST(TaskBankTest, undoTaskListAddTask)
{
	TaskBank* taskBank = new TaskBank();
	TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
	taskBankCommand->Backup();
	TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
	
	taskBank->addTask(taskList);
	taskBankCommand->Backup();
	taskBank->addTask(t1);
	taskBankCommand->Backup();

	taskBankCommand->Undo();
	taskBankCommand->Undo();
	
	TaskBank* _taskBank = new TaskBank();
        TaskList* _taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
	_taskBank->addTask(_taskList);


	std::stringstream s;
	std::stringstream output;
	
	_taskBank->display(s);
	taskBank->display(output);
	EXPECT_EQ(s.str(), output.str());
	
	delete _taskBank;		
	delete taskBankCommand;
}

TEST(TaskBankTest, undoTaskListDeleteTaskList)
{
	TaskBank* taskBank = new TaskBank();
        TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
	taskBankCommand->Backup();
        TaskList* taskList = new TaskList("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));
        
        taskBank->addTask(taskList);
        taskBankCommand->Backup();
        taskBank->deleteTask(taskList);
        taskBankCommand->Backup();

        taskBankCommand->Undo();
        taskBankCommand->Undo();
	taskBankCommand->Undo();	

        TaskBank* _taskBank = new TaskBank();

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());
        
        delete _taskBank;		
	delete taskBankCommand;
	
}

TEST(TaskBankTest, undoTaskListDeleteTask)
{
        TaskBank* taskBank = new TaskBank();
        TaskBankCommand* taskBankCommand = new TaskBankCommand(taskBank);
        taskBankCommand->Backup();
        Task* task = new Task("TaskList 1", "This is my first tasklist", "Test", 5, Date("03/08/2021"));

        taskBank->addTask(task);
        taskBankCommand->Backup();
        taskBank->deleteTask(task);
        taskBankCommand->Backup();
	
        taskBankCommand->Undo();
        taskBankCommand->Undo();
        taskBankCommand->Undo();
	
	TaskBank* _taskBank = new TaskBank();

        std::stringstream s;
        std::stringstream output;

        _taskBank->display(s);
        taskBank->display(output);
        EXPECT_EQ(s.str(), output.str());

        delete _taskBank;
        delete taskBankCommand;

}

TEST(TaskBankTest, TaskBankDeleteTaskByString)
{
	TaskBank* taskBank = new TaskBank();
	Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	

	taskBank->addTask(t1);
	taskBank->addTask(t2);
	taskBank->addTask(t3);
	taskBank->deleteTask(t3->getTaskName());	

	std::stringstream s;
	taskBank->display(s);
		
	TaskBank* correctTaskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));

	correctTaskBank->addTask(_t1);
        correctTaskBank->addTask(_t2);

	std::stringstream correctOutput;
	correctTaskBank->display(correctOutput);

	EXPECT_EQ(s.str(),correctOutput.str());
	delete taskBank;
	delete correctTaskBank;


}

TEST(TaskBankTest, TaskBankDeleteTaskByReference)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));


        taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
        taskBank->deleteTask(t3);

        std::stringstream s;
        taskBank->display(s);

        TaskBank* correctTaskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));

        correctTaskBank->addTask(_t1);
        correctTaskBank->addTask(_t2);

        std::stringstream correctOutput;
        correctTaskBank->display(correctOutput);

        EXPECT_EQ(s.str(),correctOutput.str());
        delete taskBank;
        delete correctTaskBank;

}

TEST(TaskBankTest, TaskBankDeleteTaskListByString)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* taskList = new TaskList("TaskList 1"," This is my first taskList", "Test", 2, Date("11/03/2121"));

        taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
        taskBank->addTask(taskList);
	taskBank->deleteTask(taskList->getTaskName());
	
        std::stringstream s;
        taskBank->display(s);

        TaskBank* correctTaskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        correctTaskBank->addTask(_t1);
        correctTaskBank->addTask(_t2);
        correctTaskBank->addTask(_t3);

        std::stringstream correctOutput;
        correctTaskBank->display(correctOutput);

        EXPECT_EQ(s.str(),correctOutput.str());
        delete taskBank;
        delete correctTaskBank;
}

TEST(TaskBankTest, TaskBankDeleteTaskListByReference)
{
        TaskBank* taskBank = new TaskBank();
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	TaskList* taskList = new TaskList("TaskList 1"," This is my first taskList", "Test", 2, Date("11/03/2121"));

        taskBank->addTask(t1);
        taskBank->addTask(t2);
        taskBank->addTask(t3);
	taskBank->addTask(taskList);
	taskBank->deleteTask(taskList);	

        std::stringstream s;
        taskBank->display(s);

        TaskBank* correctTaskBank = new TaskBank();
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
	Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        correctTaskBank->addTask(_t1);
        correctTaskBank->addTask(_t2);
	correctTaskBank->addTask(_t3);

        std::stringstream correctOutput;
        correctTaskBank->display(correctOutput);

        EXPECT_EQ(s.str(),correctOutput.str());
        delete taskBank;
        delete correctTaskBank;

}

TEST(TaskBankTest, sortByDueDate_TaskBank)
{
	TaskBank* tb = new TaskBank();
	TaskBank* _tb = new TaskBank();
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
	
	tb->addTask(taskList1);
	tb->addTask(t1);
        tb->addTask(t2);
        tb->addTask(t3);
        tb->sortByDueDate(); // print task 1, task 3, tl1,  task 2

	
        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* _taskList1 = new TaskList("Updated CS100","Updated Labs for CS100", "New School" , 5, Date("03/11/2021"));
        _tb->addTask(_t1);
	_tb->addTask(_t3);
        _tb->addTask(_taskList1);
        _tb->addTask(_t2);

        std::stringstream s;
        std::stringstream output;

        taskList1->viewTask(s);
        taskList1->viewTask(output);

        EXPECT_EQ(s.str(), output.str());

        delete tb;
        delete _tb;
}

TEST(TaskBankTest, sortByPriority_TaskBank)
{
        TaskBank* tb = new TaskBank();
        TaskBank* _tb = new TaskBank();
        TaskList* taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"));
        taskList1->setTaskName("Updated CS100 Labs");
        taskList1->setTaskDescription("Updated Labs for CS100");
        taskList1->setTaskType("New School");
        taskList1->setTaskPriority(5);
        taskList1->setTaskDueDate(Date("03/11/2021"));
        Task* t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        tb->addTask(taskList1);
        tb->addTask(t1);
        tb->addTask(t2);
        tb->addTask(t3);
        tb->sortByPriority(); // print task 1, task 3, tl1,  task 2


        Task* _t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task* _t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task* _t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));
        TaskList* _taskList1 = new TaskList("Updated CS100","Updated Labs for CS100", "New School" , 5, Date("03/11/2021"));
        _tb->addTask(_t1);
        _tb->addTask(_t3);
        _tb->addTask(_t2);
        _tb->addTask(_taskList1);

        std::stringstream s;
        std::stringstream output;

        taskList1->viewTask(s);
        taskList1->viewTask(output);

        EXPECT_EQ(s.str(), output.str());

        delete tb;
        delete _tb;
}


#endif