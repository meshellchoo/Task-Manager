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

####OMT Diagramn description
The OMT Diagram depicts the Comoposite Design pattern and the Memento
design pattern. The Memento Design pattern implementation features two mementos (TaskMemento and TaskBankMemento) based off of two originators (TaskObject and 
TaskBank.There are two mementos because there are two different originator 
classes. The TaskMemento is intertwined with the TaskObject originator class,
which is the Component of the Compoiste Design Pattern implementation, while 
Task and TaskList are the Leaf and Composite, respectively. 

~ 
