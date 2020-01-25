/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/25 16:55:59 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
//ERRORS
	printf("\n[testing for errors]\n\n");
	printf("fd[%d] return[%d]\n", fd0, get_next_line(fd0, &line));
	printf("fd[%d] return[%d]\n", fd4, get_next_line(fd4, &line));
//ONE FD
	printf("\n[testing single fd]\n\n");
	while (state1 > 0)
	{
		state1 = get_next_line(fd1, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd1, state1, line);
		if (state1 >= 0)
			free(line);
	}
//MULTIPLE
	printf("\n[testing multiple fds]\n\n");
	while (state2 > 0 && state3 > 0)
	{
		state2 = get_next_line(fd2, &line);
		printf("fd[%d] ret[%d] line ->%s\n", fd2, state2, line);
		if (state2 >= 0)
			free(line);
		state3 = get_next_line(fd3, &line);
		printf("fd[%d] ret[%d] line ->%s\n", fd3, state3, line);
		if (state3 >= 0)
			free(line);
	}
//while (1){}
	return (0);
}
