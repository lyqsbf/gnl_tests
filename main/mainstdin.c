/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaqliu <yaqliu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 19:07:45 by yaqliu            #+#    #+#             */
/*   Updated: 2025/12/08 13:03:15 by yaqliu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The purpose of this main is to read from stdin (standard input)

Instructions:
1. Compile the necessary files with mainstdin.c
2. Run your program.
3. Write whatever you want in the shell and your function should print it back.
*/

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
