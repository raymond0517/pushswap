/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:18:06 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 14:50:16 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	intstr(long l, char *s, int *i)
{
	if (l > 9)
	{
		intstr(l / 10, s, i);
		s[*i] = (char)('0' + (int)(l % 10));
	}
	else
		s[*i] = (char)('0' + (int)l);
	(*i)++;
	s[*i] = '\0';
}

static void	pnbr(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;
	char	s[20];
	int		i;

	l = (long)n;
	i = 0;
	if (l == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	else
	{
		if (l < 0)
		{
			l = l * (-1);
			s[0] = '-';
			i = 1;
		}
		intstr(l, s, &i);
	}
	pnbr(s, fd);
}
/*
void	pputnbr(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
}

#include <stdio.h>

int	main(void)
{ 
	printf("\n-0, -1, -10, 1, 10, 2147483647, -2147483648," \
	" -83649, 0, -1000, 50");
	pputnbr(-0, 1);
	pputnbr(-1, 1);
	pputnbr(-10, 1);
	pputnbr(1, 1);
	pputnbr(10, 1);
	pputnbr(2147483647, 1);
	pputnbr(-2147483648, 1);
	pputnbr(-83649, 1);
	pputnbr(0, 1);
	pputnbr(-1000, 1);
	pputnbr(+50, 1);
	return (0);
} */
