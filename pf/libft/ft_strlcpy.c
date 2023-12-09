/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 03:38:06 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/14 18:49:41 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* return len of src, if sz = 0, dst is untouched , max (sz - 1) copied
	plus \0 if src less or equal than (sz - 1) will entire src to dst,
	if sz = 1 will copy \0 to dst[0], sz should hv max sizeof(dst)
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t sz)
{
	size_t	ret;
	int		i;

	ret = 0;
	while (src[ret])
		ret++;
	if (sz == 0)
		return (ret);
	i = 0;
	while (i < ((int)sz) - 1)
	{
		dst[i] = ((char *)src)[i];
		if (dst[i] == '\0')
			return (ret);
		i++;
	}
	dst[i] = '\0';
	return (ret);
}
/*
#include <bsd/string.h>
#include <stdio.h>

void	pstrlcpy(char *dst, char *d2, const char *src, size_t size)
{
	printf("\ndst (%s) src (%s), sz (%lu)", dst, (char *)src, size);
	printf("\nsrc len(%lu), ", strlcpy(dst, src, size));
	printf("  dst now (%s)", dst);
	printf("\nft src len(%lu), ", ft_strlcpy(d2, src, size));
	printf("d2 now (%s)\n", d2);
}

int	main(void)
{
	char	s[21];
	char	s2[21];

	pstrlcpy(s, s2, "abcde", 10);
	pstrlcpy(s, s2, "", 0);
	pstrlcpy(s, s2, "", 10);
	pstrlcpy(s, s2, "0123456789", 10);
	pstrlcpy(s, s2, "0123456789", 1);
	pstrlcpy(s, s2, "", 1);
	pstrlcpy(s, s2, "0123456789", 1);
	pstrlcpy(s, s2, "0123456789", 0);
	pstrlcpy(s, s2, "012345678901234567890123456789", 2);
	pstrlcpy(s, s2, "012345678901234567890123456789", 5);
	pstrlcpy(s, s2, "012345678901234567890123456789", 20);
	pstrlcpy(s, s2, "012345678901234567890123456789", 21);
	pstrlcpy(s, s2, "", 0);
	return (0);
} */
