/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:54:45 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/16 03:58:06 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t sz)
{
	char	*s;
	size_t	tot;
	size_t	i;

	tot = nmemb * sz;
	s = (char *)malloc(nmemb * sz);
	if (s != NULL)
	{
		i = 0;
		while (i < tot)
			s[i++] = 0;
	}
	return (s);
}

int	chkzero(char *s, size_t sz)
{
	size_t	i;

	i = 0;
	while (i < sz)
	{
		if (s[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
#include <errno.h>
#include <string.h>

void pcalloc(size_t nmemb, size_t sz)
{
	char	*s1;
	char	*s2;

	printf("\nnmemb (%lu), sz (%lu)", nmemb, sz);
	s1 = ft_calloc(nmemb, sz);
	if (s1 == NULL)
		printf("\nreturn NULL ptr (%s)", strerror(errno));
	else
	{
		if (((size_t)nmemb * (size_t)sz) == 0)
			printf("\n(FT) Zero byte allocated, and not NULL");
			
		printf("\nSuccess FT calloc chk all bytes zero %d", \
		chkzero(s1, (size_t)nmemb * sz));
		free(s1);
	}
	s2 = calloc(nmemb, sz);
	if (s2 == NULL)
		printf("\nreturn NULL ptr (%s)", strerror(errno));
	else
	{
		if (((size_t)nmemb * (size_t)sz) == 0)
			printf("\nZero byte allocated, and not NULL");

		printf("\nSuccess calloc chk all bytes zero %d", \
		chkzero(s2, (size_t)nmemb * sz));
		free(s2);
	}

}

int	main(void)
{
	pcalloc(1, 0);
	pcalloc(0, 1);
	pcalloc(1, 1);
	pcalloc(0, 0);
	pcalloc((size_t)65536 * 65536, (size_t)65535 * 65536 / 2);
	pcalloc((size_t)65536, (size_t)65536);
	return (0);
} */
