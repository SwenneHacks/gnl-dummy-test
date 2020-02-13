/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:53:24 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/13 18:00:08 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
