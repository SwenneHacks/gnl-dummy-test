/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/10 22:12:33 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	int		ret2;
	int		ret3;
	char	*line;

	ret = 1;
	ret2 = 1;
	ret3 = 1;
	fd = open("oscar-wilde.txt", O_RDONLY);
	fd2 = open("get_next_line.h", O_RDONLY);
	fd3 = open("", O_RDONLY);
	close(42);
	while (ret > 0 && ret2 > 0 && ret3 > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%d->%s\n", ret, line);
		// if (ret >= 0)
		// 	free(line);
		// ret2 = get_next_line(fd2, &line);
		// printf("%d->%s\n", ret2, line);
		// if (ret2 >= 0)
		// 	free(line);
		// ret3 = get_next_line(fd3, &line);
		// printf("%d->%s\n", ret3, line);
		// if (ret3 >= 0)
		// 	free(line);
	}
	//while (1){}
	return (0);
}