########################################################################
# Zoe Sarwar (cssc0802), Patrick Perrine (cssc0801)
# CS 570 Summer 2019
# Assignment #3, emp
# Makefile
########################################################################

FILE = emp.cpp
CC = g++
ENDFLAGS = -pthread
NAMEFILE = emp

Compile:
   $ g++ -std=c++11 -o emp -pthread emp.cpp
   
Run:
  ./emp
   
Clean:
  rm -rf emp

        
########################[ EOF: Makefile ]################################

