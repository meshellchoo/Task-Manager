CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test src/main.cpp)

ADD_EXECUTABLE(TaskListSortTest 
/home/csmajs/mchu017/cs100-task-manager/tests/TaskListSortTest.cpp 
#/home/csmajs/mchu017/cs100-task-manager/tests/TaskListDeleteTaskTest.cpp


/home/csmajs/mchu017/cs100-task-manager/src/TaskList.cpp
/home/csmajs/mchu017/cs100-task-manager/src/Task.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
