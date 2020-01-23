/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:03 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/23 20:02:06 by swofferh      ########   odam.nl         */
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

static char		*copy_buffer(char *old, char *new, size_t n)
{
	char	*next;
	size_t	len;

	if (old == NULL)
	{
		next = (char *)malloc(sizeof(char) * (n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, new, n);
	}
	else
	{
		len = scan_index(old, '\0');
		next = (char *)malloc(sizeof(char) * (len + n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, old, len);
		free(old);
		ft_strncpy(next + len, new, n);
	}
	return (next);
}

static t_state	read_line(t_list *buf, char **out)
{
	ssize_t	ret;
	size_t	i;

	if (buf->size == 0)
	{
		ret = read(buf->fd, buf->content, BUFFER_SIZE);
		if (ret == end_file || ret == error)
			return (ret);
		buf->content[ret] = '\0';
		buf->size = ret;
	}
	i = scan_index(buf->content, '\n');
	*out = copy_buffer(*out, buf->content, i);
	if (*out == NULL)
		return (error);
	if (i < buf->size)
	{
		buf->size = buf->size - i - 1;
		ft_strncpy(buf->content, buf->content + i + 1, buf->size);
		return (line_read);
	}
	else
		buf->size = 0;
	return (loop);
}

int				get_next_line(int fd, char **line)
{
	static t_list		*buf_list;
	t_list				*buf;
	char				*out;
	t_state				state;

	buf = get_buffer(fd, &buf_list);
	if (buf == NULL)
		return (error);
	out = NULL;
	state = loop;
	while (state == loop)
		state = read_line(buf, &out);
	if (state == line_read)
		*line = out;
	if (state == end_file)
	{
		*line = copy_buffer(out, "", 0);
		free_buffer(fd, &buf_list);
		if (*line == NULL)
			return (error);
	}
	if (state == error)
		free_buffer(fd, &buf_list);
	return (state);
}
