/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 02:52:43 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/10 03:15:31 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		s++;
		cnt++;
	}
	return (cnt);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("len %lu\n", ft_strlen(""));
	printf("len %lu\n", ft_strlen("a"));
	printf("len %lu\n", ft_strlen("\t\f\n"));
	printf("len %lu\n", ft_strlen("\0"));
	printf("expected results : 0, 1 3 0");
	return (0);
} */
