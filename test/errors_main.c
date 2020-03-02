/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: swofferh <swofferh@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 22:08:52 by swofferh       #+#    #+#                */
/*   Updated: 2020/02/29 19:55:45 by swofferh      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int     main(void)
{
        int             fd_0;
        int             fd_42;
        int             fd_43;
        char   			 *line;

		fd_0 = open("", O_RDONLY);
  		fd_42 = 42;
        fd_43 = 43;
//ERRORS
        printf("\n~~~~~~~~~~~~~~~~~~ testing for errors \n\n");
        printf("fd[%d] return[%d]\n", fd_0, get_next_line(fd_0, &line));
        printf("fd[%d] return[%d]\n", fd_42, get_next_line(fd_42, &line));
        printf("fd[%d] return[%d]\n", fd_43, get_next_line(fd_43, &line));
//LEAKS
        printf("\n~~~~~~~~~~~~~~~~~~ testing for leaks ~\n\n");
        //while (1){}
        printf("  [OK]  \n\n");
        return (0);
}
