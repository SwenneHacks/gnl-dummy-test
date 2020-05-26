/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/29 20:29:23 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd2;
	int		fd1;
	char	*line;
	int		state1;
	int		state2;

	state1 = 1;
	state2 = 1;
	fd2 = open("read.txt", O_RDONLY);
	fd1 = open("poem.txt", O_RDONLY);

	printf("\n~~~~~~~~~~~~~~~~~~~~~ testing multiple fds]\n\n");
	while (state1 > 0 && state2 > 0)
	{
		state1 = get_next_line(fd2, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd2, state1, line);
		if (state1 >= 0)
			free(line);
		state2 = get_next_line(fd1, &line);
		printf("fd[%d] ret[%d] line->%s\n", fd1, state2, line);
		if (state2 >= 0)
			free(line);
	}
}

