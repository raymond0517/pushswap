/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:55:20 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/10 02:40:04 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	sc;

	sc = (char)c;
	while (*s)
	{
		if (sc == *s)
			return ((char *)s);
		s++;
	}
	if (sc == '\0')
		return ((char *)s);
	else
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
	printf("\n() c\n");
	p_ptr(ft_strchr("", 'c'));
	printf("\n");
	p_ptr(strchr("", 'c'));
	printf("\n(abccdefg c!@#$) c\n");
	p_ptr(ft_strchr("abccdefg c!@#$", 'c'));
	printf("\n");
	p_ptr(strchr("abccdefg c!@#$", 'c'));
	printf("\n(abccdefg c!@#$) $\n");
	p_ptr(ft_strchr("abccdefg c!@#$", '$'));
	printf("\n");
	p_ptr(strchr("abccdefg c!@#$", '$'));
	printf("\n(abcdefg !@#$) \\0\n");
	p_ptr(ft_strchr("abcdefg !@#$", '\0'));
	printf("\n");
	p_ptr(strchr("abcdefg !@#$", '\0'));
	printf("\n(abcdefg !@#$) ' '\n");
	p_ptr(ft_strchr("abcdefg !@#$", ' '));
	printf("\n");
	p_ptr(strchr("abcdefg !@#$", ' '));
	printf("\n(abcdefg !@#$) h\n");
	p_ptr(ft_strchr("abcdefg !@#$", 'h'));
	printf("\n");
	p_ptr(strchr("abcdefg !@#$", 'h'));
	printf("\n(abcdefg\\t!@#$) \\t\n");
	p_ptr(ft_strchr("abcdefg	!@#$", '	'));
	printf("\n");
	p_ptr(strchr("abcdefg	!@#$", '	'));
	printf("\n(abcdefg !@#$) \\n\n");
	p_ptr(ft_strchr("abcdefg !@#$", '\n'));
	printf("\n");
	p_ptr(strchr("abcdefg !@#$", '\n'));
	printf("\n(abcdefg !@#$) 0\n");
	p_ptr(ft_strchr("abcdefg !@#$", 0));
	printf("\n");
	p_ptr(strchr("abcdefg !@#$", 0));
	return (0);
} */
