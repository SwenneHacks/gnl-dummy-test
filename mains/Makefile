# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh       #+#    #+#                 #
#    Updated: 2019/12/22 21:42:57 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

DIR	= ../../done/
#write down the path of your gnl above, mine is here for now.
FLAGS 	= -Wall -Werror -Wextra

SRC = 	$(DIR)get_next_line.c $(DIR)get_next_line_utils.c

BONUS =	$(DIR)get_next_line_bonus.c $(DIR)get_next_line_utils_bonus.c

#TESTS:

read:
	$(CC) $(FLAGS) $(SRC) test_read.c -o output_read
	@echo ""
	@echo "Trying to understand what is it that 'read' really does:\n"
	@./output_read
	@echo ""

simple:
	$(CC) $(FLAGS) $(SRC) test_mandatory.c -o output_simple
	@echo ""
	@echo "Testing mandatory part with easy checkups:\n"
	@./output_simple
	@echo ""

bonus:
	$(CC) $(FLAGS) $(BONUS) test_bonus.c -o output_bonus
	@echo ""
	@echo "Testing bonus part with multiple fds:\n"
	@./output_bonus
	@echo ""

errors:
	$(CC) $(FLAGS) $(SRC) test_errors.c -o output_errors_simple
	@echo ""
	@echo "Mandatory Part\n"
	@./output_errors_simple
	@echo ""
	$(CC) $(FLAGS) $(BONUS) test_errors.c -o output_errors_bonus
	@echo ""
	@echo "Bonus Part\n"
	@./output_errors_bonus
	@echo ""

catE:
	@./output_simple | cat -e

clean:
	@$(RM) a.out output_*
