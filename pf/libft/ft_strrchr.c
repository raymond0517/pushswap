/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:55:20 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/10 02:41:36 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"  

char	*ft_strrchr(const char *s, int c)
{
	char	sc;
	char	*start;

	start = (char *)s;
	sc = (char)c;
	while (*s)
		s++;
	if (sc == '\0')
		return ((char *)s);
	while (s != start)
	{
		s--;
		if (*s == sc)
			return ((char *)s);
	}
	return (NULL);
}
/*
#include <stdio.h>

void	p_ptr(char *ptr)
{
	if (ptr == NULL)
		printf("NULL");
	else if (*ptr == '\0')
		printf("points to '\\0'");
	else
		printf("%s", ptr);
}

#include <string.h>

int	main(void)
{
	printf("\n(abccdefg c!@#$) c\n");
	p_ptr(ft_strrchr("abccdefg c!@#$", 'c'));
	printf("\n");
	p_ptr(strrchr("abccdefg c!@#$", 'c'));
	printf("\n() c\n");
	p_ptr(ft_strrchr("", 'c'));
	printf("\n");
	p_ptr(strrchr("", 'c'));
	printf("\n(abccdefg c!@#$) $\n");
	p_ptr(ft_strrchr("abccdefg c!@#$", '$'));
	printf("\n");
	p_ptr(strrchr("abccdefg c!@#$", '$'));
	printf("\n(abcdefg !@#$) \\0\n");
	p_ptr(ft_strrchr("abcdefg !@#$", '\0'));
	printf("\n");
	p_ptr(strrchr("abcdefg !@#$", '\0'));
	printf("\n(abcdefg  !@#$) ' '\n");
	p_ptr(ft_strrchr("abcdefg  !@#$", ' '));
	printf("\n");
	p_ptr(strrchr("abcdefgi  !@#$", ' '));
	printf("\n(abcdefg !@#$) h\n");
	p_ptr(ft_strrchr("abcdefg !@#$", 'h'));
	printf("\n");
	p_ptr(strrchr("abcdefg !@#$", 'h'));
	printf("\n(abc\\tdefg\\t!@#$) \\t\n");
	p_ptr(ft_strrchr("abc	defg	!@#$", '	'));
	printf("\n");
	p_ptr(strrchr("abc	defg	!@#$", '	'));
	printf("\n(abcdefg !@#$) \\n\n");
	p_ptr(ft_strrchr("abcdefg !@#$", '\n'));
	printf("\n");
	p_ptr(strrchr("abcdefg !@#$", '\n'));
	printf("\n(abcdefg !@#$) 0\n");
	p_ptr(ft_strrchr("abcdefg !@#$", 0));
	printf("\n");
	p_ptr(strrchr("abcdefg !@#$", 0));
	return (0);
} */
