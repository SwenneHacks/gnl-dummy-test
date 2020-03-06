/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:53:24 by swofferh       #+#    #+#                */
/*   Updated: 2020/03/04 21:38:37 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*copy_buffer(char *old, char *new, int n)
{
	char	*next;
	int		len;

	if (old == NULL)
	{
		next = (char *)malloc(sizeof(char) * (n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, new, n);
	}
	else
	{
		len = ft_strclen(old, '\0');
		next = (char *)malloc(sizeof(char) * (len + n + 1));
		if (next == NULL)
			return (NULL);
		ft_strncpy(next, old, len);
		free(old);
		ft_strncpy(next + len, new, n);
	}
	return (next);
}

char		*ft_strncpy(char *dst, const char *src, int n)
{
	int		index;

	index = 0;
	while (index < n)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (dst);
}

int			ft_strclen(char *str, char c)
{
	int		index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
