CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(TaskListSortTest 
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListSortTest.cpp 
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListDeleteTaskTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/taskManagerTest.cpp
#tests/taskManagerTest.cpp
src/main.cpp
src/TaskBankMemento.cpp
src/helperFunctions.cpp
src/TaskManager.cpp
src/TaskList.cpp
src/Task.cpp
src/TaskObject.cpp
src/TaskBankCommand.cpp
src/TaskBank.cpp
)


ADD_EXECUTABLE(TaskManager
/home/csmajs/jooi001/cs100-task-manager/tests/taskManagerTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/taskManagerTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/taskManagerTest.cpp
#tests/taskManagerTest.cpp
#src/main.cpp
src/helperFunctions.cpp
#src/TaskManager.cpp
src/TaskList.cpp
src/Task.cpp
src/TaskBankMemento.cpp
src/TaskObject.cpp
src/TaskBankCommand.cpp
src/TaskBank.cpp
src/TaskManager.cpp
)

ADD_EXECUTABLE(unitTest
tests/unit_test.cpp
#src/main.cpp
#src/helperFunctions.cpp
#src/TaskManager.cpp
src/TaskList.cpp
src/Task.cpp
src/TaskBankMemento.cpp
src/TaskObject.cpp
src/TaskBankCommand.cpp
src/TaskBank.cpp
#src/TaskManager.cpp
)


#TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(TaskListSortTest gtest)
TARGET_LINK_LIBRARIES(TaskManager gtest)
TARGET_LINK_LIBRARIES(unitTest gtest)


TARGET_COMPILE_DEFINITIONS(TaskListSortTest PRIVATE gtest_disable_pthreads=ON)

TARGET_COMPILE_DEFINITIONS(TaskManager PRIVATE gtest_disable_pthreads=ON)

TARGET_COMPILE_DEFINITIONS(unitTest PRIVATE gtest_disable_pthreads=ON)

