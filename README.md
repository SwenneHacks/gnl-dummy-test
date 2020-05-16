# get_next_line
A handy function that reads files (on multiple descriptors) line by line.

"The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor. Because reading a line on a fd is way too tedious..." - quoted by 42

## DONE FOLDER:

Is my submitted project (handy short version).

## TEST FOLDER:

Contains my testing files for both the bonus part and the simplified version. I tried to keep them apart because there was a lot of cleaning to do and also too much 'moving around' to compare both results so I used a cleaning script for that and two other testing scrits that run the output right after creating the test result - which I find it very usefull.

### Goals: 

This project will not only allow you to add a very convenient function to your collection (library), but it will also allow you to learn a highly interesting new concept in C programming: static variables, file descriptors management and the usage of -D BUFFER_SIZE (flag & macro).

### SIMPLE version:

Contains the first version of my get next line function with the mandatory requirements of the 42 network project-subject (pdf included in this repository). It has multiple static variables and as far as I know I only handles a single open file descriptor. 

### BONUS version:

Contains funtions that manage multiple descriptors (while reading) with the usage of a single static variable.

Read the gidelines.pdf for more info about this project.
