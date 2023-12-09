/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:34:59 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/13 02:58:51 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uintptr_t		d;
	uintptr_t		s;
	size_t			i;

	d = (uintptr_t)dest;
	s = (uintptr_t)src;
	if ((n == 0) || (d == s))
		return (dest);
	if (d > s)
	{
		while (n-- != 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

void	pft_memmove(void *dest, const void *src, size_t n)
{
	char	old[50];
	int		i;

	i = 0;
	while (((char *)dest)[i])
	{
		old[i] = ((char *)dest)[i];
		i++;
	}
	old[i] = '\0';
	printf("\nmemmove dest (%s), src (%s), n (%lu)", (char *)dest, \
	(char *)src, n);
	printf("\nft (%s)", (char *)ft_memmove(dest, src, n));
	printf("\nSy (%s)", (char *)memmove(old, src, n));
}

int	main(void)
{
	char	s1[50] = "Hello World! We are the champion my friend!";
	char	s2[50] = "In the morning, when the moon is at its rest";

	pft_memmove(s2, s2, 10);
	pft_memmove(s2, s2, 0);
	pft_memmove(s1, s2, 0);
	pft_memmove(s2, s1, 10);
	s1[10] = '!';
	s1[0] = '@';
	pft_memmove(s1 + 10, s1, 10);
	s1[10] = 'A';
	s1[0] = 'a';
	pft_memmove(s1, s1 + 10, 10);
	printf("\ns1 (%s)", s1);
	printf("\ns2 (%s)", s2);
	return (0);
} */
