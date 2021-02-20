#ifndef __TASKLIST_CPP__
#define __TASKLIST_CPP__

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
void TaskList::restore(TaskMemento t){

}

#endif 
