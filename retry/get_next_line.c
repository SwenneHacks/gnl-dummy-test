/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:03 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/29 19:40:45 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_state	read_line(int fd, char *buf, char **out, int *size)
{
	ssize_t	ret;
	int		i;

	if (*size == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == END_FILE || ret == ERROR)
			return (ret);
		buf[ret] = '\0';
		*size = ret;
	}
	i = ft_strclen(buf, '\n');
	*out = copy_buffer(*out, buf, i);
	if (*out == NULL)
		return (ERROR);
	if (i < *size)
	{
		*size = *size - i - 1;
		ft_strncpy(buf, buf + i + 1, *size);
		return (ONE_LINE);
	}
	else
		*size = 0;
	return (LOOP);
}

int				get_next_line(int fd, char **line)
{
	static char			buf[BUFFER_SIZE + 1];
	static int			size;
	char				*out;
	t_state				ret;

	out = NULL;
	ret = LOOP;
	while (ret == LOOP)
		ret = read_line(fd, buf, &out, &size);
	if (ret == ONE_LINE)
		*line = out;
	if (ret == END_FILE)
	{
		*line = copy_buffer(out, "", 0);
		if (*line == NULL)
			return (ERROR);
	}
	return (ret);
}
