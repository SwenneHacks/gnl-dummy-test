
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		ret;
	int		rd;
	char	*line;
	int		linecount;
	char	buf[5];

	ret = 1;
	linecount = 1;
	fd = open("read.txt", O_RDONLY);
	close(42);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (linecount > 9)
			printf("fd[%d] ret[%d] line[%d] ->%s\n", fd, ret, linecount, line);
		if (linecount < 10)
			printf("fd[%d] ret[%d] line[0%d] ->%s\n", fd, ret, linecount, line);
		if (ret >= 0)
			free(line);
		linecount++;
	}
	rd = read(fd, buf, 4);
	printf("function read return: %i\n", rd);
}
