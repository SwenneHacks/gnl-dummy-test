/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/12 23:00:25 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../simple/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd0;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		state1;
	int		state2;
	int		state3;
	int		state0;

	state1 = 1;
	state2 = 1;
	state3 = 1;
	state0 = 1;
	fd0 = open("", O_RDONLY);
	fd1 = open("oscar-wilde.txt", O_RDONLY);
	fd2 = open("get_next_line.h", O_RDONLY);
	fd3 = open("get_next_line.c", O_RDONLY);
	fd4 = 42;
	close(42);
//ONE FD
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~ testing single fd \n\n");
	while (state1 > 0)
	{
		state1 = get_next_line(fd1, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd1, state1, line);
		if (state1 >= 0)
			free(line);
	}
//ERRORS
	printf("\n~~~~~~~~~~~~~~~~~~ testing for errors \n\n");
	printf("fd[%d] return[%d]\n", fd0, get_next_line(fd0, &line));
	printf("fd[%d] return[%d]\n", fd4, get_next_line(fd4, &line));
//LEAKS
	printf("\n~~~~~~~~~~~~~~~~~~ testing for leaks ~\n\n");
	//while (1){}
	printf("  [OK]  \n\n");
	return (0);
}
