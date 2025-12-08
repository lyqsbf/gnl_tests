/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaqliu <yaqliu@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:25:28 by yaqliu            #+#    #+#             */
/*   Updated: 2025/12/07 18:14:48 by yaqliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
