/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:53:24 by swofferh       #+#    #+#                */
/*   Updated: 2020/01/23 18:54:57 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		free_buffer(int fd, t_list **lst)
{
	t_list	*node;
	t_list	*recursive;

	node = *lst;
	if (node->fd == fd)
	{
		*lst = node->next;
		free(node->content);
		free(node);
	}
	else if (node->next->fd == fd)
	{
		recursive = node->next;
		node->next = node->next->next;
		free(recursive->content);
		free(recursive);
	}
	else
		free_buffer(fd, &node->next);
}

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

size_t		scan_index(char *str, char c)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			break ;
		index++;
	}
	return (index);
}
