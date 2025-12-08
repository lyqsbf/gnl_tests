/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaqliu <yaqliu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 18:29:02 by yaqliu            #+#    #+#             */
/*   Updated: 2025/12/08 12:58:58 by yaqliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of this main is to make sure that your ft_get_next_line_bonus is working
properly

Instructions:
1. Compile the necessary files with mainbonus.c
2. Run your program with the files you select.
   (This main accepts various files as arguments. Your function should read
    simultaneously from all the files and display the lines interspersed; the output
    will be in different colors.)

    NOTE: if you wish to test your function with a non-existent fd, you can simply
          enter the name of a non-existent file as an argument.

To ensure that you do not have any memory leaks, you can use Valgrind when
running your program:
valgrind --leak-check=full
*/

#include "get_next_line_bonus.h"
#include <stdio.h>

//definition of colours
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int	main(int argc, char **argv)
{
	int		i;
	int		n;
	int		fd[MAX_FD];
	int		not_ended;
	char	*line;

	char	*colors[] = {YELLOW, BLUE, RED, GREEN, MAGENTA, CYAN};
	int		num_colors = 6;

	if (argc > 1)
	{
		printf("\n-----openining file(s)-----\n");
		i = 1;
		while (i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			if (fd[i] == -1)
				printf("Error while opening file: %s\n", argv[i]);
			i++;
		}

		printf("\n-----Reading files----\n");
		n = 1;
		not_ended = 1;
		while (not_ended)
		{
			not_ended = 0;
			i = 1;
			while (i < argc)
			{
				line = get_next_line(fd[i]);
				if (line)
				{
					char	*current_color = colors[(i - 1)%num_colors];
					printf("%sline %i (%s):\n%s%s", current_color, n, argv[i], line, RESET);
					free(line);
					not_ended = 1;
				}
				i++;
			}
			n++;
		}
		while (i < argc)
		{
			if (fd[i] != -1)
				close(fd[i]);
			i++;
		}
	}
	return (0);
}
