/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/29 20:45:30 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		ret;
	char	*line;
	int		linecount;

	ret = 1;
	linecount = 1;
	fd = open("poem.txt", O_RDONLY);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~ testing mandatory part (SINGLE FD) \n\n");
	
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (linecount > 9)
			printf("fd[%d] ret[%d] line[%d] ->%s\n", fd, ret, linecount, line);
		if (linecount < 10)
			printf("fd[%d] ret[%d] line[0%d] ->%s\n", fd, ret, linecount, line);
		if (ret >= 0)
			free(line);
		if (ret == 0)
		{
			printf ("      ret[0]\n");
			break ;
		}
		linecount++;
	}
}
