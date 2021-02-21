#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

#include "/home/csmajs/jooi001/cs100-task-manager/header/TaskList.hpp"
//#include "/home/csmajs/mchu017/cs100-task-manager/header/TaskList.hpp"
//#include "/home/csmajs/htran164/cs100-task-manager/header/TaskList.hpp"

void TaskList::clear(){
    tasks.clear();
}
void TaskList::deleteTask(Task task){
    for(std::vector<Task>::iterator i = tasks.begin(); i != tasks.end(); i++){
        if(i == task)
            tasks.erase(i);
    }
    
}
void TaskList::addTask(Task task){
    tasks.push_back(task);
}
void TaskList::viewTask(){

}
TaskObject* TaskList::createTaskMemento(){
    
}
//void TaskList::restore(TaskMemento t){

//}

#endif 
