# CS 100 Final Project - Task Manager
#### Group Members: Michelle Chu, Huan Tran, James Ooi
#### Github Pages: https://github.com/meshellchoo, https://github.com/ethanotran, https://github.com/galacticgoob
#### Project Description: 
#### Motive
  - As college students, we find the task manager project important because we find it difficult to mange our time wisely. With the surge of online classes, many classes use different websites to submit assignments, which makes it difficult to manage all the assignments. With the task manager, we can use a single platform to keep track of all of these assignments and also set the priority of these assignments to create an effective task list. Additionally, we can include our personal and work tasks too to make the most out of the application.
#### Languages/Tools/Technologies
  - We plan on using C++, git, Vim, C++ gui libraries, and PuTTY. 
#### Input/Output
  - The input of our project will be the task title, description, classification (similiar to a tag), priority, duration, and due date. Additionally, the user can create a task list and input the title, description, tasks, and priority of that task list.
  - Our project will have two outputs based on if the user decides to view a task or task list. If the user decides to view a task, it will output all the information about the task. If the user decides to view a task list, it will output a neatly arranged task list based on the added tasks' priority and due date.
#### Design Patterns
  - We picked the Composite Pattern because we think it will be useful for task and tasklist to share a common interface. The feature we will implement allows the user to add tasks or tasklists onto their task manager. By using composite, we avoid the problem of having a lot of classes in our code and allows the tasks to share a common interface. This design pattern allows us to treat primitive (task) and container (tasklist) types the same. With this design pattern, we can produce families of related objects (tasklist, task, etc.) without specifying the concrete class, task class.

  - We picked the Memento Pattern because we think it will be useful when trying to incorporate the undo function for the Task Feature and Task Lists Feature. The Memento Pattern allows us to create a "memento" object to store the current state of the "originator" object, thus allowing us to return to a previous state after committing to a change. Without this design pattern, the "memento" object would not be able to access private properties of the "originator" object. A problem we anticipate encountering when implementing the project is that the user can accidentally delete/edit a task or task list with no way of restoring them. With the Memento Pattern, they can undo the deletion/editting and bring back their previous task or task list.


#### OMT Diagram

![](CS100%20Final%20Project%20OMT%20Diagram.jpg)

#### Class Diagram Description

  - The OMT Diagram depicts a Composite Design Pattern and the Memento Design Pattern. The Composite Pattern is implemented in the Task and TaskList Classes as both classes redefine functions the TaskObject Class has. The TaskObject, Task, and TaskList class use protected member variables for taskName, description, taskType, priority, and dueDate so that the derived classes can use these member variables. Additionally, the TaskList Class has an addtional private member variable, std::vector<Task> Tasks, and has additional functions addTask(Task task), deleteTask(Task task), and clear(), which allows TaskList to represent a large task with subtasks. The Memento Pattern is implemented using originator, memento, and command classes for the TaskObject and TaskBank Classes. Going more in depth, the TaskMemento Class initializes a TaskObject to make a copy of a previous state of a task. The TaskCommand Class allows us to backup the previous state and revert back to that previous state. Ultimately, the TaskMemento Class uses a private member variable TaskObject (originator) Class object, which is a prime example of the Composite Pattern and Memento Pattern working together.
Task and TaskList are the Leaf and Composite, respectively. 


Moreover, the TaskBank classes use a separate Memento pattern because it uses a separate originator class than the TaskObject classes. The TaskBankCommand class acts the same as the TaskCommand class except it's specified for TaskBank only. The TaskBank has a vector of TaskObject* and is a collection of all of the TaskObjects that has been created. The TaskManager has a TaskBank as its private member. The TaskManager is basically a simple user interface and the user should only be able to access the run() function and be able to add tasks, delete tasks, sort tasks etc.

The OMT Diagram depicts the Comoposite Design pattern and the Memento
design pattern. The Memento Design pattern implementation features two mementos (TaskMemento and TaskBankMemento) based off of two originators (TaskObject and 
TaskBank.There are two mementos because there are two different originator 
classes. 
