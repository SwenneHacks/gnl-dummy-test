/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:03 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/25 16:19:59 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list			*get_buffer(int fd, t_list **lst)
{
	t_list	*node;
	t_list	*new;

	node = *lst;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	new->size = 0;
	new->fd = fd;
	new->next = *lst;
	*lst = new;
	return (new);
}

static t_state	read_line(t_list *buf, char **out)
{
	ssize_t	ret;
	size_t	i;

	if (buf->size == 0)
	{
		ret = read(buf->fd, buf->content, BUFFER_SIZE);
		if (ret == END_FILE || ret == ERROR)
			return (ret);
		buf->content[ret] = '\0';
		buf->size = ret;
	}
	i = scan_index(buf->content, '\n');
	*out = copy_buffer(*out, buf->content, i);
	if (*out == NULL)
		return (ERROR);
	if (i < buf->size)
	{
		buf->size = buf->size - i - 1;
		ft_strncpy(buf->content, buf->content + i + 1, buf->size);
		return (READ_LINE);
	}
	else
		buf->size = 0;
	return (LOOP);
}

int				get_next_line(int fd, char **line)
{
	static t_list		*buf_list;
	t_list				*buf;
	char				*out;
	t_state				ret;

	buf = get_buffer(fd, &buf_list);
	if (buf == NULL)
		return (ERROR);
	out = NULL;
	ret = LOOP;
	while (ret == LOOP)
		ret = read_line(buf, &out);
	if (ret == READ_LINE)
		*line = out;
	if (ret == END_FILE)
	{
		*line = copy_buffer(out, "", 0);
		free_buffer(fd, &buf_list);
		if (*line == NULL)
			return (ERROR);
	}
	if (ret == ERROR)
		free_buffer(fd, &buf_list);
	return (ret);
}
