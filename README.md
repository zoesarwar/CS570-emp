# CS570 Summer 2019 Assignment 3
* Names: Zoe Sarwar, Patrick Perrine
* Red ID's: 820523074, 820486635
* Class Accounts: cssc0802, cssc0801
* CS 570, Summer 2019
* Assignment #3, emp.cpp
* Filename: README.md

## File Manifest
emp.cpp
README.md
Makefile

## Compile Instructions
* After importing all neccessary files, run the makefile using the "% make" command. 
* After compiling, the input goes directly after "$ ./emp". For instance, I would enter "$ ./emp 75 1 45" before running or pressing enter on the keyboard. 

## Operating Instructions
* Run the executable "emp". 
* See Makefile for specific compile and run commands.
* After compiling, the input goes directly after "$ ./emp". For instance, I would enter "$ ./emp 75 1 45" before running or pressing enter on the keyboard. 

## List Description of novel / significant design decisions
* There are three total pthread_creates. 
* We only used pthread_join once, with the countdown timer.
* Timer, interval and alarms are global variables.
* Use of semaphores.

## Extra Features/algorithms/functionality 

## List/Description of all known deficiencies or bugs

## Lessons Learned
We learned how to execute the following:
* Use pthread_join appropriately.
* How to implement a countdown timer in C++.
* How to print the current local time via programming.
* How to time outputs correctly with a real clock/timer.
* How to create an interval timer. 
