
#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		ret;
	char	*line;
	int		linecount;
	int		i;

	ret = 1;
	i = 0;
	linecount = 1;
	fd = open("oscar-wilde.txt", O_RDONLY);
	close(42);
	while (i < 50)
	{
		ret = get_next_line(fd, &line);
		if (linecount > 9)
			printf("fd[%d] ret[%d] line[%d] ->%s\n", fd, ret, linecount, line);
		if (linecount < 10)
			printf("fd[%d] ret[%d] line[0%d] ->%s\n", fd, ret, linecount, line);
		if (ret >= 0)
			free(line);
		linecount++;
		i++;
	}
}
