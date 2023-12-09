/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:57:50 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/10 02:36:07 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cnt;

	if (n == 0)
		return (0);
	cnt = 0;
	while (1)
	{
		if ((*s1 != *s2) || (*s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		cnt++;
		s1++;
		s2++;
		if (cnt == n)
			return (0);
	}
}
/*
#include <stdio.h>

void	p_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	printf("%d", ft_strncmp(s1, s2, n));
	printf(", %d\n", strncmp(s1, s2, n));
}

int	main(void)
{
	p_ft_strncmp("", "", 0);
	p_ft_strncmp("a", "a", 1);
	p_ft_strncmp("", "", 1);
	p_ft_strncmp("", "", 2);
	p_ft_strncmp("", "a", 0);
	p_ft_strncmp("a", "a ", 1);
	p_ft_strncmp("a ", "a", 1);
	p_ft_strncmp("a ", "a", 2);
	p_ft_strncmp("abc", "abc", 4);
	p_ft_strncmp("abc ", "abc", 4);
	p_ft_strncmp("a c ", "abc", 1);
	p_ft_strncmp("a c ", "abc", 4);
	p_ft_strncmp("", "abc", 3);
	p_ft_strncmp("abc", "", 3);
	return (0);
} */
