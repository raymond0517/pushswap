/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:20:00 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/29 20:33:07 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	long			slen;
	unsigned int	i;
	char			*r;

	slen = ft_strlen(s);
	if (start + len > (unsigned int)slen)
	{
		if (slen - (long)start > 0)
			len = slen - start;
		else
			len = 0;
	}
	r = (char *)malloc((len + 1) * sizeof(char));
	if (r != NULL)
	{
		i = 0;
		while (i < len)
		{
			r[i] = s[start + i];
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
/*
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	psubstr(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	s1 = ft_substr(s, start, len);
	if (s1 == NULL)
		printf("\nNULL ptr (%s)", strerror(errno));
	else
	{
		printf("\nsubstr (%s)", s1);
		free(s1);
	}
}

int	main(void)
{
	psubstr("hola", 4294967295, 0);
	psubstr("", 10, 10);
	psubstr("hello", 5, 5);
	psubstr("hello", 5, 0);
	psubstr("in the morning", 0, 0);
	psubstr("in the morning", 5, 0);
	psubstr("in the morning", 10, 10);
	psubstr("in the morning", 0, 10);
	psubstr("in the morning", 0, 1);
	psubstr("in the morning", 10, 1);
	return (0);
} */
