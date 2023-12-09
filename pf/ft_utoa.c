/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:51:38 by rhsu              #+#    #+#             */
/*   Updated: 2023/10/13 00:17:46 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static char	*alloc_intstr(char *s)
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

char	*ft_utoa(unsigned int n)
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
