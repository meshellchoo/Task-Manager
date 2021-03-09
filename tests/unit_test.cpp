#ifndef _UNIT_TEST_
#define _UNIT_TEST_

#include "gtest/gtest.h"
#include "Date.hpp"
#include "Task.hpp"
#include "TaskBank.hpp"
#include "TaskBankCommand.hpp"
#include "TaskList.hpp"
#include "TaskManager.hpp"
#include "TaskBankMemento.hpp"
#include "TaskObject.hpp"
#include "helperFunctions.hpp"

int main (int argc, char** argv){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}


TEST(TaskTest, createTaskDefaultConstructor)
{
	Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
	EXPECT_EQ("", t1.view());
	delete t1;
}

TEST(TaskTest, setTaskName)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
	t1.setTaskName("Updated Task 1");
        EXPECT_EQ("Updated Task 1", t1.getTaskName());
        delete t1;
}

TEST(TaskTest, setTaskDescription)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
	t1.setTaskDescription("This is my updated first task");
        EXPECT_EQ("This is my updated first task", t1.getTaskDescription());
        delete t1;
}

TEST(TaskTest, setTaskType)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        EXPECT_EQ("New Test", t1.getTaskType());
        delete t1;
}

TEST(TaskTest, setTaskPriority)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
	t1.setTaskPriority(3);
        EXPECT_EQ(3, t1.getTaskPriority());
        delete t1;

}

TEST(TaskTest, setTaskDueDate)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
	t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021"), t1.getTaskDueDate());
        delete t1;

}

TEST(TaskTest, getTaskName)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("Updated Task 1" , t1.getTaskName());
        delete t1;

}

TEST(TaskTest, getTaskDescription)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("This is my updated first task" , t1.getTaskDescription());
        delete t1;
}

TEST(TaskTest, getTaskType)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("New Test" , t1.getTaskType());
        delete t1;

}

TEST(TaskTest, getTaskPriority)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(3 , t1.getTaskPriority());
        delete t1;
}

TEST(TaskTest, getTaskDueDate)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021") , t1.getTaskDueDate());
        delete t1;
}

TEST(TaskTest, viewTask)
{
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        t1.setTaskName("Updated Task 1");
        t1.setTaskDescription("This is my updated first task");
        t1.setTaskType("New Test");
        t1.setTaskPriority(3);
        t1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(    , t1.viewTask());
        delete t1;
}

TEST(TaskListTest, createTaskListDefaultConstructor)
{
	TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
	EXPECT_EQ();
	delete taskList1;

}

/*
TEST(TaskListTest, createTaskListVectorConstructor)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"), std::vector<Task> )
        EXPECT_EQ()
        delete taskList1;

}
*/

TEST(TaskListTest, setTaskListName)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
	EXPECT_EQ("Updated CS100 Labs" , taskList1.getTaskName());
        delete taskList1;
}

TEST(TaskListTest, setTaskListDescription)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
	EXPECT_EQ("Updated Labs for CS100", taskList1.getTaskDescription());
        delete taskList1;

}

TEST(TaskListTest, setTaskListType)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
	taskList1.setTaskType("New School");
        EXPECT_EQ("New School", taskList1.getTaskType());
        delete taskList1;
}

TEST(TaskListTest, setTaskListPriority)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" , 2, Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
	taskList1.setTaskPriority(5);
	EXPECT_EQ(5, taskList1.getTaskPriority());
        delete taskList1;
}

TEST(TaskListTest, setTaskListDueDate)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
	taskList1.setTaskType("New School");
	taskList1.setTaskPriority(5);
 	taskList1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(Date("03/11/2021"), taskList1.getTaskDueDate());
        delete taskList1;
}


TEST(TaskListTest, getTaskListName)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
	taskList1.setTaskType("New School");
	taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("Updated CS100 Labs", taskList1.getTaskName());
        delete taskList1;
}


TEST(TaskListTest, getTaskListDescription)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
	EXPECT_EQ("Updated Labs for CS100", taskList1.getTaskDescription());
        delete taskList1;
}

TEST(TaskListTest, getTaskListType)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ("New School", taskList1.getTaskType());
        delete taskList1;
}

TEST(TaskListTest, getTaskListPriority)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        EXPECT_EQ(5, taskList1.getTaskPriority());
        delete taskList1;
}

TEST(TaskListTest, addTask)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
	Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

	taskList1.addTask(t1);
	taskList1.addTask(t2);
	taskList1.addTask(t3);

        EXPECT_EQ( , taskList1.viewTask());
        delete taskList1;
}

TEST(TaskListTest, deleteTask)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1.addTask(t1);
        taskList1.addTask(t2);
        taskList1.addTask(t3);

	taskList1.deleteTask(t2);

        EXPECT_EQ( , taskList1.viewTask()); // should not print taske 2
        delete taskList1;
}

TEST(TaskListTest, clearTaskList)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1.addTask(t1);
        taskList1.addTask(t2);
        taskList1.addTask(t3);

        taskList1.clear();

        EXPECT_EQ( , taskList1.viewTask()); // should not print taske 2
        delete taskList1;
}

TEST(TaskListTest, sortByDueDate_TaskList)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/20/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/16/2021"));

        taskList1.addTask(t1);
        taskList1.addTask(t2);
        taskList1.addTask(t3);

        taskList1.sortByDueDate();

        EXPECT_EQ( , taskList1.viewTask()); // print task 2, task 3, task 1
        delete taskList1;


}

TEST(TaskListTest, sortByPriority_TaskList)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1.addTask(t1);
        taskList1.addTask(t2);
        taskList1.addTask(t3);

        taskList1.sortByPriority();

        EXPECT_EQ( , taskList1.viewTask()); // print task 1, task 3, task 2
        delete taskList1;
}

TEST(TaskListTest, viewTaskList)
{
        TaskList taskList1 = new TaskList("CS100 Labs","Labs for CS100", "School" ,2,Date("02/27/2021"))
        taskList1.setTaskName("Updated CS100 Labs");
        taskList1.setTaskDescription("Updated Labs for CS100");
        taskList1.setTaskType("New School");
        taskList1.setTaskPriority(5);
        taskList1.setTaskDueDate(Date("03/11/2021"));
        Task t1 = new Task("Task 1", "This is my first task", "Test", 5, Date("03/08/2021"));
        Task t2 = new Task("Task 2", "This is my second task", "Test", 3, Date("03/11/2021"));
        Task t3 = new Task("Task 3", "This is my third task", "Test", 4, Date("03/09/2021"));

        taskList1.addTask(t1);
        taskList1.addTask(t2);
        taskList1.addTask(t3);

        EXPECT_EQ( , taskList1.viewTask()); // print task 1, task 2, task 3
        delete taskList1;

}

TEST(TaskBankTest, addTask_TaskBank)
{

}

TEST(TaskBankTest, deleteTask_TaskBank)
{

}

TEST(TaskBankTest, clearTaskBank)
{

}

TEST(TaskBankTest, searchTaskBank)
{

}

TEST(TaskBankTest, display)
{

}

TEST(TaskBankTest, undoTaskEdit)
{

}


TEST(TaskBankTest, undoTaskListEdit)
{

}

TEST(TaskBankTest, undoTaskListAddTask)
{

}

TEST(TaskBankTest, undoTaskListDeleteTask)
{

}



TEST(TaskBankTest, undoTaskBankDelete)
{

}
