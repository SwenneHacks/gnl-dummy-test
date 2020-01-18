/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/18 18:16:11 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line;
	int		state1;
	int		state2;
	int		state3;

	state1 = 1;
	state2 = 1;
	state3 = 1;
	fd1 = open("oscar-wilde.txt", O_RDONLY);
	fd2 = open("get_next_line.h", O_RDONLY);
	fd3 = open("get_next_line.pdf", O_RDONLY);
	//close(42);
	while (state1 > 0 && state2 > 0 && state3 > 0)
	{
		state1 = get_next_line(fd1, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd1, state1, line);
		if (state1 >= 0)
			free(line);
		state2 = get_next_line(fd2, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd2, state2, line);
		if (state2 >= 0)
			free(line);
		state3 = get_next_line(fd3, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd3, state3, line);
		if (state3 >= 0)
			free(line);
	}
	//while (1){}
	return (0);
}