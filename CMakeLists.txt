CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test src/main.cpp)

ADD_EXECUTABLE(TaskListSortTest 
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListSortTest.cpp 
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListDeleteTaskTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/taskManagerTest.cpp
tests/taskManagerTest.cpp
src/helperFunctions.cpp
src/TaskManager.cpp
src/TaskList.cpp
src/Task.cpp
src/TaskMemento.cpp
)


ADD_EXECUTABLE(TaskMementoTest
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListSortTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListDeleteTaskTest.cpp
#/home/csmajs/mchu017/cs100-task-manager/tests/taskManagerTest.cpp
tests/taskManagerTest.cpp
src/helperFunctions.cpp
src/TaskManager.cpp
src/TaskList.cpp
src/Task.cpp
src/TaskMemento.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
