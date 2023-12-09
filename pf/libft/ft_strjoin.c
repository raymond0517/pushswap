/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 01:21:18 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/29 23:39:02 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s1_s2_len(size_t *t1, size_t *t2, char const *s1, char const *s2)
{
	*t1 = 0;
	while (((char *)s1)[*t1])
		(*t1)++;
	*t2 = 0;
	while (((char *)s2)[*t2])
		(*t2)++;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t1;
	size_t	t2;
	char	*r;
	size_t	i;
	size_t	j;

	s1_s2_len(&t1, &t2, s1, s2);
	r = (char *)malloc((size_t)(t1 + t2 + 1) * (sizeof(char)));
	if (r != NULL)
	{
		i = 0;
		while (i < t1)
		{
			r[i] = ((char *)s1)[i];
			i++;
		}
		j = 0;
		while (j < t2)
		{
			r[i + j] = ((char *)s2)[j];
			j++;
		}
		r[t1 + t2] = '\0';
	}
	return (r);
}
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	pstrjoin(const char *s1, const char *s2)
{
	char	*r;

	r = ft_strjoin(s1, s2);
	if (r == NULL)
		printf("\nNULL ptr (%s)", strerror(errno));
	else
	{
		printf("\nconcat (%s)", r);
		free(r);
	}
}

int	main(void)
{
	pstrjoin("", "");
	pstrjoin("a", "");
	pstrjoin("a\n", "b\nc");
	pstrjoin("Hello ", "World !");
	return (0);

} */
