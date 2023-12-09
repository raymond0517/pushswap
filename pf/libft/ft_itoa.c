/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:22:00 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 14:49:44 by rhsu             ###   ########.fr       */
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

char	*alloc_intstr(char *s)
{
	size_t	i;
	char	*r;

	i = 0;
	while (s[i])
		i++;
	r = (char *)malloc(sizeof(char) * (i + 1));
	if (r != NULL)
	{
		i = 0;
		while (s[i])
		{
			r[i] = s[i];
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}

char	*ft_itoa(int n)
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
	return (alloc_intstr(s));
}
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	pft_itoa(int n)
{
	char	*r;

	r = ft_itoa(n);
	if (r == NULL)
		printf("\nNULL ptr (%s)", strerror(errno));
	else
	{
		printf("\n (%d), str (%s)", n, r);
		free(r);
	}
}

int	main(void)
{
	pft_itoa(-0);
	pft_itoa(-1);
	pft_itoa(-10);
	pft_itoa(1);
	pft_itoa(10);
	pft_itoa(2147483647);
	pft_itoa(-2147483648);
	pft_itoa(-83649);
	pft_itoa(0);
	pft_itoa(-1000);
	pft_itoa(+50);
	return (0);
} */
