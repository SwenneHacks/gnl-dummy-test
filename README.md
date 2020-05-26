# get\_next\_line
A handy function that reads files (on multiple descriptors) line by line.


"The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor. Because reading a line on a fd is way too tedious..." - quoted by 42


### Goals:

This project will not only allow you to add a very convenient function to your collection (library), but it will also allow you to learn a highly interesting new concept in C programming: static variables, file descriptors management and the usage of -D BUFFER\_SIZE (flag & macro).


### BONUS version:

Contains functions that manage multiple descriptors (while reading) with usage of linked/chained lists. Also, in comparison to the other version (SIMPLE folder) it has a single static variable (my struct).


### SIMPLE version:

Contains the first version of my get next line function with the mandatory requirements of the 42 network project-subject (pdf included in this repository). It has multiple static variables and as far as I know I only handles a single open file descriptor. But correct me if I'm wrong! More about my testing folder bellow ↴

## MY TESTS (MAINS FOLDER):

Contains my testing files for both the bonus part and the simplified version. I kept it with 'int main(void)' just so begginers can compile it the way the like. If they choose to use the Makefile it will be there to see what it does (with clean and cat -e rules).

I tried to keep them apart because there was all the 'moving around' and commenting it on/off all the time to compare both results so I used a cleaning script for that and two other testing scripts that run the output right after creating the test result - which I find it very useful.

Wanna see how it works? Use the flag -D BUFFER\_SIZE=1 and also -g if you've got a debugger (search lldb) so you can follow the 'reading' process and buffer management of this function. Enjoy debugging 'a la pythontutor.com style' if you know what I mean ;)

## MY GNL (DONE FOLDER) :

My submitted project (handy short version).
