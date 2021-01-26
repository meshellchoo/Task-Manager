# CS 100 Final Project - Task Manager
# Group Members: Michelle Chu, Huan Tran, James Ooi
# Github Pages: https://github.com/meshellchoo, https://github.com/ethanotran, https://github.com/galacticgoob
# Project Description: 
# Why is it important or interesting to you?
  - As college students, we find the task manager project important because we find it difficult to mange our time wisely. With the surge of online classes, many classes use different websites to submit assignments, which makes it difficult to manage all the assignments. With the task manager, we can use a single platform to keep track of all of these assignments and also set the priority of these assignments to create an effective task list. Additionally, we can include our personal and work tasks too to make the most out of the application.
# What languages/tools/technologies do you plan to use?
  - We plan on using C++, git, Vim, C++ gui libraries, and PuTTY. 
# What will be the input/output of your project?
  - 
# What are the two design patterns you will be using? 
  - 

  - We picked the Memento Pattern because we think it will be useful when trying to incorporate the undo function for the Task Feature and Task Lists Feature. The Memento Pattern allows us to create a "memento" object to store the current state of the "originator" object, thus allowing us to return to a previous state after committing to a change. Without this design pattern, the "memento" object would not be able to access private properties of the "originator" object. A problem we anticipate encountering when implementing the project is that the user can accidentally delete/edit a task or task list with no way of restoring them. With the Memento Pattern, they can undo the deletion/editting and bring back their previous task or task list.
