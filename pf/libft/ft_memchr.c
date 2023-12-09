/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 18:54:04 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/29 17:01:56 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	size_t			cnt;
	unsigned char	*str;

	cnt = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (cnt < n)
	{
		if (uc == str[cnt])
			return (str + cnt);
		cnt++;
		if (cnt == n)
			return (NULL);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

void	p_ft_memchr(void *src, int c, size_t n)
{
	char	*ret;

	printf("Start testing (%s), (%c), (%lu)\n", (char *)src, c, n);
	ret = (char *)ft_memchr(src, c, n);
	if (ret == NULL)
		printf("(NULL)");
	else
		printf("(%s) %lu bytes", ret, strlen(ret));
	printf("\nactual memchr");
	ret = memchr(src, c, n);
	if (ret == NULL)
		printf("(NULL)");
	else
		printf("(%s) %lu bytes", ret, strlen(ret));
	printf("\n");
}

int	main(void)
{
	p_ft_memchr("abcdefg  123", 'c', 1);
	p_ft_memchr("abcdefg  123", 'c', 3);
	p_ft_memchr("abcdefg  123", 'c', 4);
	p_ft_memchr("abcdefg  123", 'c', 0);
	p_ft_memchr("", 'c', 0);
	p_ft_memchr("", 'c', 1);
	p_ft_memchr("", 'c', 2);
	p_ft_memchr("", 0, 0);
	p_ft_memchr("", 0, 1);
	p_ft_memchr("abc", 0, 0);
	p_ft_memchr("abc", 0, 1);
	p_ft_memchr("abc", 0, 3);
	p_ft_memchr("abc	aa", '\t', 3);
	p_ft_memchr("abc	aa", '\t', 4);
	p_ft_memchr("abc	aa", '\t', 5);
	return (0);
} */
