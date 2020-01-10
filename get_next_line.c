/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:03 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/10 22:05:02 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		free_recursive(t_list *lst, int fd)
{
	t_list	*text;

	if (lst->next->fd == fd)
	{
		text = lst->next;
		lst->next = lst->next->next;
		free(text->content);
		free(text);
	}
	else
		free_recursive(lst->next, fd);
}

static void		free_buffer(t_list **lst, int fd)
{
	t_list	*node;

	node = *lst;
	if (node->fd == fd)
	{
		*lst = node->next;
		free(node->content);
		free(node);
	}
	else
		free_recursive(node, fd);
}

static t_state	read_line(t_list *buf, char **out)
{
	ssize_t	ret; //How is that even possible?
	size_t	i;

	if (buf->size == 0)
	{
		ret = read(buf->fd, buf->content, BUFFER_SIZE);
		if (ret == end_read || ret == error)
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

	buf = get_buffer(&buf_list, fd); //WTF is this?
	if (buf == NULL)
		return (error);
	out = NULL;
	state = loop;
	while (state == loop)
		state = read_line(buf, &out);
	if (state == line_read)
		*line = out;
	if (state == end_read)
	{
		*line = copy_buffer(out, "", 0);
		free_buffer(&buf_list, fd);
		if (*line == NULL)
			return (error);
	}
	if (state == error)
		free_buffer(&buf_list, fd);
	return (state);
}
