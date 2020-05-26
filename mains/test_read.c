/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_read.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 14:49:20 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/04 21:38:13 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		ret;
	int		rd;
	char	*line;
	int		linecount;
	char	buf[10];

	ret = 1;
	linecount = 1;
	fd = open("read.txt", O_RDONLY);
	rd = read(fd, buf, 6);

	printf("buf = %.5s|\n", buf);

	if (rd > 0)
		printf("function read return: %i\n\n", rd);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (linecount > 9)
			printf("fd[%d] ret[%d] line[%d] >%s|\n", fd, ret, linecount, line);
		if (linecount < 10)
			printf("fd[%d] ret[%d] line[0%d] >%s|\n", fd, ret, linecount, line);
		if (ret >= 0)
			free(line);
		linecount++;
	}
}
