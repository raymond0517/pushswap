/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker10_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 03:06:48 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/08 17:26:19 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* will only read when previous read does not return 0 byte or remaining
	chars not processed doesn't contain \n */
void	read_pipe_data(char *b, int *tot, int ptr)
{
	static int	stopread;
	int			i;

	i = ptr;
	while (i < *tot)
	{
		if (b[i] == '\n')
			return ;
		i++;
	}
	if (!stopread)
	{
		i = read(0, b + *tot, PIPE_DATA_MAX - *tot);
		*tot += i;
		if (i == 0)
			stopread = 1;
	}
}

int	three_or_four_byte_instruction(char *l, char *b, int p, int tot)
{
	l[0] = b[p + 0];
	l[1] = b[p + 1];
	l[2] = b[p + 2];
	if (l[2] != '\n')
	{
		if ((p + 4) <= tot)
		{
			l[3] = b[p + 3];
			return (4);
		}
	}
	return (3);
}
