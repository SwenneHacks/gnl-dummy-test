# get\_next\_line 
A handy function that reads files (on multiple descriptors) line by line.

 
"The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor. Because reading a line on a fd is way too tedious..." - quoted by 42
 

### Goals:

This project will not only allow you to add a very convenient function to your collection (library), but it will also allow you to learn a highly interesting new concept in C programming: static variables, file descriptors management (ropen/read/close) and the usage of -D BUFFER\_SIZE (flag & macro). Try to study those before getting into this project.


### BONUS version:

This function should manage multiple descriptors (while reading), in my case I used an implementation of linked lists for that. Also, in comparison to the other version (SIMPLE version bellow) it has a single static variable (in my case that's my static struct).

### SIMPLE version:

Should contain a get next line function with the mandatory requirements of the 42 network project-subject (pdf included in this repository). You're allowed to use more than just one static variable and handle just a single open fd but it should return -1 for errors and not zero. More about my testing folder (for errors) bellow ↴

## TESTS (FOLDER 'MAINS'):

Contains my testing files for both the bonus part and the simplified version. I kept it with 'int main(void)' just so beginners can compile it the way the like. If they choose to use the Makefile it will be there to see what it does (with clean and cat -e rules).

HOW TO TEST: 

**| make read | make simple | make bonus | make errors |**

I tried to keep them apart because there was all the 'moving around' and commenting it on/off all the time to compare both results so I used a cleaning script for that and two other testing scripts that run the output right after creating the test result - which I find it very useful.

Wanna see how it works? Use the flag -D BUFFER\_SIZE=1 and also -g if you've got a debugger (search lldb) so you can follow the 'reading' process and buffer management of this function. Enjoy debugging 'a la pythontutor.com style' if you know what I mean ;)

## MY GNL (FOLDER 'DONE') :

My submitted project (handy short version).
