/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 21:54:19 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/13 17:34:09 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef enum		e_state
{
	ONE_LINE = 1,
	END_FILE = 0,
	ERROR = -1,
	LOOP = 2
}					t_state;

int					get_next_line(int fd, char **line);
char				*copy_buffer(char *old, char *new, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
size_t				scan_index(char *str, char c);

#endif
