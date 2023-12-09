/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 02:05:36 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/11 04:38:36 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	if (n > 0)
	{
		ch = (unsigned char)c;
		str = (unsigned char *)s;
		while (n != 0)
		{
			*str = ch;
			str++;
			n--;
		}
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

void	p_ft_memset(void *str, void *str2, int c, size_t n)
{
	printf("\n\n fill (%c) (%lu) times\n", c, n);
	if (n > 10)
		printf("B4 set (%s)\n", (char *)str);
	printf("(%s)\n", (char *)ft_memset(str, c, n));
	printf("(%s)\n", (char *)memset(str2, c, n));
}

int	main(void)
{
	char	s1[15] = "in the morning";
	char	s2[17] = "you will find me";
	char	s3[2] = "z";
	char	s4[2] = "@";
	char	s5[15] = "in the morning";
	char	s6[17] = "you will find me";
	char	s7[2] = "z";
	char	s8[2] = "@";

	p_ft_memset(s5, s1, 'K', 4);
	p_ft_memset(s5, s1, 'm', 0);
	p_ft_memset(s5, s1, 'n', 1);
	p_ft_memset(s5, s1, 'w', 15);
	p_ft_memset(s5, s1, 'p', 20);
	p_ft_memset(s7, s3, 0, 1);
	p_ft_memset(s7, s3, 0, 3);
	printf("\ns1 (%s)", s1);
	printf("\ns2 (%s)", s2);
	printf("\ns3 (%s)", s3);
	printf("\ns4 (%s)", s4);

	printf("\ns5 (%s)", s5);
	printf("\ns6 (%s)", s6);
	printf("\ns7 (%s)", s7);
	printf("\ns8 (%s)", s8);

	return (0);
} */
