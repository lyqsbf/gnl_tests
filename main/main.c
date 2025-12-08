/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaqliu <yaqliu@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:25:28 by yaqliu            #+#    #+#             */
/*   Updated: 2025/12/08 13:01:26 by yaqliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of this main is to make sure that your ft_get_next_line_bonus is working
properly

Instructions:
1. Compile the necessary files with main.c
2. Run your program with the files you choose.
   (This main accepts various files as arguments, but unlike the bonus part,
    your get_next_line should display the files one by one, it shouldn't read
    simultaneously from all the files as the bonus part does.)

    NOTE: If you wish to test your function a non-existent fd, you can simply
          enter the name of a non-existent file as an argument.

To ensure that you do not have any memory leaks, you can use Valgrind when
running your program:
valgrind --leak-check=full
*/

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	int		fd;
	char	*line;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			printf("\n-----reading file#%i------\n", i);
			fd = open(argv[i], O_RDONLY);
			line = get_next_line(fd);
			n = 1;
			while (line)
			{
				printf("line %i:\n%s", n, line);
				free(line);
				line = get_next_line(fd);
				n++;
			}
			close(fd);
			i++;
		}
	}
}
