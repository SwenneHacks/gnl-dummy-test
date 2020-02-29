/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 21:53:24 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/15 14:38:30 by swofferh      ########   odam.nl         */
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

char		*copy_buffer(char *old, char *new, size_t n)
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
