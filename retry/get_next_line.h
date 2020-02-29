/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:19 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/29 20:20:59 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef enum		e_state
{
	ONE_LINE = 1,
	END_FILE = 0,
	ERROR = -1,
	LOOP = 2
}					t_state;

int					get_next_line(int fd, char **line);
char				*copy_buffer(char *old, char *new, int n);
char				*ft_strncpy(char *dst, const char *src, int n);
int					ft_strclen(char *str, char c);

#endif
