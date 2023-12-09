/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:29:49 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/11 15:15:38 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>

void	p_ft_bzero(char *s1, char *s2, size_t n)
{
	ft_bzero(s1, n);
	bzero(s2, n);
	for (unsigned int i = 0; i < 22; i++)
		printf("(%d)", s1[i]);
	printf("-\n");
	for (unsigned int i = 0; i < 22; i++)
		printf("(%d)", s2[i]);
	printf("-\n");
}

int	main(void)
{
	char	s1[21] = "abcdefghij0123456789";
	char	s2[2] = "#";
	char	s3[21] = "abcdefghij0123456789";
	char	s4[2] = "#";

	p_ft_bzero(s1, s3, 0);
	printf("\ns1 (%s) s2(%s) s3(%s) s4(%s)\n", s1, s2, s3, s4);
	p_ft_bzero(s1, s3, 1);
	printf("\ns1 (%s) s2(%s) s3(%s) s4(%s)\n", s1, s2, s3, s4);
	p_ft_bzero(s1, s3, 3);
	printf("\ns1 (%s) s2(%s) s3(%s) s4(%s)\n", s1, s2, s3, s4);
	p_ft_bzero(s1, s3, 21);
	printf("\ns1 (%s) s2(%s) s3(%s) s4(%s)\n", s1, s2, s3, s4);
	p_ft_bzero(s1, s3, 22);
	printf("\ns1 (%s) s2(%s) s3(%s) s4(%s)\n", s1, s2, s3, s4);
	return (0);
} */
