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

NAME 	= get_next_line.a
INC 	= get_next_line.h
FLAGS 	= -Wall -Werror -Wextra
TEST	= 

SRC = 	../get_next_line.c \
	../get_next_line_utils.c \
	../get_next_line_bonus.c \
	./get_next_line_utils_bonus.c

OBJ = 	$(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $@ $^
	@ranlib $(NAME)
	@mkdir obj
	@mv $(OBJ) obj
	@echo "~~~~ Done creating get_next_line.a \n"
	
%.o: %.c
	@echo "Compiling $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
	
clean:
	@$(RM) -rf obj
	@echo "Removing $@"
	@echo "~~~~ Done Cleaning \n"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $@"
	@echo "~~~~ Done with (F)abulous (Clean)ing \n"

re: fclean all
	@echo "~~~~ Done Restarting \n"

test_simple: re
	$(CC) $(FLAGS) $(TEST) $(NAME) -o output_simple
	@echo ""
	@./$output_simple

fix: re
	@gcc -g $(FLAGS) $(TEST) $(NAME)
	@echo "---- Done compiling for debugger.\n"
	@/a.out

add:
	git add $(SRC) Makefile $(INC) $(TEST)
	git status
