/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:29:11 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/11 19:37:42 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	long unsigned int	i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void	p_cmp(const char *s1, const char *s2, size_t n)
{
	printf("\ns1 (%s), s2(%s), (%lu)", s1, s2, n);
	printf("\n(%d), (%d)", ft_memcmp(s1, s2, n), memcmp(s1, s2, n));
}

int	main(void)
{
	char	s1[10] = "abc";
	char	s2[10] = "abc";
	char	s3[10] = "hij";
	char	s4[10] = "hij";

	p_cmp("abc", "abc", 0);
	p_cmp("", "abc", 0);
	p_cmp("abc", "", 0);
	p_cmp("", "", 0);
	p_cmp("abc", "abc", 1);
	p_cmp("", "abc", 1);
	p_cmp("abc", "", 1);
	p_cmp("", "", 1);
	p_cmp("abc", "abd", 3);
	p_cmp(s1, s2, 11);
	p_cmp(s3, s4, 12);
	return (0);
} */
