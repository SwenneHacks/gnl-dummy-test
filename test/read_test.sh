echo "\n~~~~~~~~~~~~~ Imput:"
cat read.txt
echo "\n~~~~~~~~~~~~~Output:"
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main_read.c -g -o read_output |
./read_output