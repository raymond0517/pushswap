/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:50:50 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/28 17:04:53 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	it returns length of src + number of chars in dst within the sz bytes 
	before \0, if within sz bytes in dst, \0 doesn't exists, it means 
	dst has length of sz, and no bytes are copied from src

	within sz bytes in dst, if dst original length takes up odst bytes,
	then (sz - odst) bytes will be available to copy src content into it.
	1 byte will be reserved for \0 to terminate dst
*/

#include "libft.h"

static int	getlen(char *dst, const char *src, int *slen, size_t sz)
{
	int	dlen;

	*slen = 0;
	while (((char *)src)[*slen])
		(*slen)++;
	dlen = 0;
	while ((dlen < (int)sz) && (dst[dlen]))
		dlen++;
	return (dlen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t sz)
{
	int	slen;
	int	dlen;
	int	byte2copy;
	int	i;

	dlen = getlen(dst, src, &slen, sz);
	byte2copy = ((int)sz) - dlen - 1;
	if (byte2copy > slen)
		byte2copy = slen;
	i = 0;
	while (i < byte2copy)
	{
		dst[dlen + i] = ((char *)src)[i];
		i++;
	}
	if (byte2copy >= 0)
		dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
#include <stdio.h>
#include <bsd/string.h>
#include <string.h>

size_t	strlcat2(char *dst, const char *src, size_t dsize)
{
	const char	*odst = dst;
	const char	*osrc = src;
	size_t		n = dsize;
	size_t		dlen;

	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}

void	pstrlcat(char *dst, const char *src, size_t size)
{
	char	d1[30];
	char	d2[30];
	char	d3[30];

	strcpy(d1, dst);
	strcpy(d2, dst);
	strcpy(d3, dst);
	printf("\ndst (%s) src (%s), sz (%lu)", dst, (char *)src, size);
	printf("\nret len(%lu), ", strlcat(d1, src, size));
	printf("   strlcat d1 now (%s)", d1);
	printf("\nret len(%lu), ", strlcat2(d2, src, size));
	printf("  strlcat2 d2 now (%s)\n", d2);
	printf("\nret len(%lu), ", ft_strlcat(d3, src, size));
	printf("ft_strlcat d3 now (%s)\n", d3);
}

int	main(void)
{
	pstrlcat("", "abcde", 10);
	pstrlcat("", "", 0);
	pstrlcat("", "", 5);
	pstrlcat("a", "", 0);
	pstrlcat("a", "", 1);
	pstrlcat("a", "", 2);
	pstrlcat("a", "b", 0);
	pstrlcat("a", "b", 1);
	pstrlcat("a", "b", 2);
	pstrlcat("a", "b", 3);
	pstrlcat("a", "bc", 2);
	pstrlcat("a", "bc", 3);
	pstrlcat("abc", "", 1);
	pstrlcat("abc", "012", 1);
	pstrlcat("abc", "012", 3);
	pstrlcat("abc", "012", 4);
	pstrlcat("abc", "012", 5);
	pstrlcat("abc", "012", 6);
	pstrlcat("abc", "012", 7);
	pstrlcat("abc", "012", 8);
	pstrlcat("abc", "", 8);
	pstrlcat("abc", "0123", 8);
	pstrlcat("abc", "0123", 9);
	pstrlcat("abc", "0123", 2020);
	return (0);
} */
