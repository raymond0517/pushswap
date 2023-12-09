/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:28:02 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/15 18:48:16 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*s;
	int		negative;
	long	n;

	s = (char *)nptr;
	while ((*s == '\t') || (*s == '\n') || (*s == '\v') || \
	(*s == '\f') || (*s == '\r') || (*s == ' '))
		s++;
	negative = 0;
	if ((*s == '+') || (*s == '-'))
	{
		if (*s == '-')
			negative = 1;
		s++;
	}
	n = 0L;
	while ((*s >= '0') && (*s <= '9'))
	{
		n = (long)((*s) - '0') + (n * 10);
		s++;
	}
	if (negative)
		n = (-1L) * n;
	return (n);
}
/*
#include <stdio.h>

void	patoi(const char *s)
{
	printf("(%s)\n", s);
	printf("ft (%d) sy (%d)\n", ft_atoi(s), atoi(s));
}

int	main(void)
{
	patoi("		\n\t\v\f   -asd;f");
	patoi("   +-1");
	patoi("		\n\t\v\f   --3sd;f");
	patoi("		\n\t\v\f   -0a245");
	patoi("14		\n\t\v\f   -asd;f");
	patoi("-0		\n\t\v\f   -asd;f");
	patoi("12		\n\t\v\f   -asd;f");
	patoi("---166sd;f");
	patoi("		\n\t\v\f   +0007asd;f");
	patoi("80211		\n\t\v\f   -asd;f");
	patoi("-166sd;f");
	patoi("+-166 sd;f");
	patoi(" +2147483647");
	patoi("-2147483648ab");
	patoi("- 100");
	return (0);
} */
