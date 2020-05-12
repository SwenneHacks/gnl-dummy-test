# get_next_line
A handy function that reads files (on multiple descriptors) line by line.


"The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor. Because reading a line on a fd is way too tedious..." - quoted by 42


### Goals: 

This project will not only allow you to add a very convenient function to your collection (library), but it will also allow you to learn a highly interesting new concept in C programming: static variables, file descriptors management and the usage of -D BUFFER_SIZE (flag & macro).


## BONUS FOLDER (private):

Contains funtions that manage multiple descriptors (while reading) with usage of linked/chained lists. Also, in comparisson to the other version (SIMPLE folder) it has a single static variable (my struct).


## SIMPLE FOLDER (private):

Contains the first version of my get next line function with the mandatory requirements of the 42 network project-subject (pdf included in this repository). It has multiple static variables and as far as I know I only handles a single open file descriptor. But correct me if I'm wrong! More about my testing folder bellow ↴

## TEST FOLDER:

Contains my testing files for both the bonus part and the simplified version. I tried to keep them apart because there was a lot of cleaning to do and also too much 'moving around' to compare both results so I kept them in one place. As you see, there's also a cleaning script and two testing scrits that run the output right after creating the test result - I find that very usefull.

Wanna see how it works? Use the flag -D BUFFER_SIZE=1 and also -g if you've got a debugger so you can follow the 'reading' process and buffer management of this function. Enjoy debbuging 'a la pythontutor.com style' if you know what I mean ;)

## DONE FOLDER:

Is my submitted project (handy short version).
