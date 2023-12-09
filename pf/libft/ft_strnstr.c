/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 03:01:29 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/13 21:00:23 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	substr(const char *s, const char *ss, \
size_t remaining, size_t ss_len)
{
	size_t	i;

	if (remaining < ss_len)
		return (0);
	i = 0;
	while (i < ss_len)
	{
		if (s[i] != ss[i])
			return (0);
		i++;
	}
	return (1);
}

static size_t	ss_len(char *ss)
{
	size_t	cnt;

	cnt = 0;
	while (ss[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strnstr(const char *s, const char *ss, size_t n)
{
	size_t	sslen;
	size_t	cnt;

	if (*ss == '\0')
		return ((char *)s);
	sslen = ss_len((char *)ss);
	cnt = 0;
	while ((cnt < n) && (*s))
	{
		if (substr(s, ss, n - cnt, sslen))
			return ((char *)s);
		s++;
		cnt++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

char *strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0') {
		len = strlen(find);
		do {
			do {
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			} while (sc != c);
			if (len > slen)
				return (NULL);
		} while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}

void	pstrnstr(const char *s, const char *ss, size_t n)
{
	char	*ft;
	char	*sy;

	ft = ft_strnstr(s, ss, n);
	sy = strnstr(s, ss, n);
	printf("\ns (%s), ss (%s), n (%lu)", s, ss, n);
	printf("\nft (%s)", (ft == NULL) ? "NULL" : ft);
	printf("\nsy (%s)", (sy == NULL) ? "NULL" : sy);
	printf("\n=============\n");
}

int	main(void)
{
	const char *ls = "Foo Bar Bas";
	const char *ss = "Bar";

	pstrnstr(ls, ss, 5);
	pstrnstr(ls, ss, 7);
	pstrnstr("bar", "bar", 4);
	pstrnstr("bar", "bar", 0);
	pstrnstr("bar", "bar", 1);
	pstrnstr("bar", "bar", 2);
	pstrnstr("bar", "bar", 3);
	pstrnstr("", "bar", 0);
	pstrnstr("", "bar", 1);
	pstrnstr("", "bar", 3);
	pstrnstr("", "", 0);
	pstrnstr("", "", 1);
	pstrnstr("bar", "", 0);
	pstrnstr("bar", "", 1);
	pstrnstr("bar", "", 2);
	pstrnstr("sdafagawarksag", "art", 8);
	pstrnstr("sdafagawarksag", "ark", 9);
	pstrnstr("a", "ark", 1);
	pstrnstr("sdafagawarksag", "ark", 10);
	pstrnstr("sdafagawarksag", "ark", 11);
	pstrnstr("sdafagawarksag", "ark", 12);
	return (0);
} */
