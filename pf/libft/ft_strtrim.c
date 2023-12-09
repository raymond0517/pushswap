/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:06:45 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 00:44:52 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimch(char c, char const *set)
{
	while (*set)
	{
		if (c == (char)*set)
			return (1);
		set++;
	}
	return (0);
}

static void	left_right_ptr(char const *s1, char const *set, size_t *l, \
size_t *r)
{
	*l = 0;
	while (s1[*l])
	{
		if (is_trimch((char)s1[*l], set))
			(*l)++;
		else
			break ;
	}
	*r = 0;
	while (s1[*r])
		(*r)++;
	while (1)
	{
		if (*r)
			(*r)--;
		else
			break ;
		if (!is_trimch((char)s1[*r], set))
			break ;
	}
}

static void	copyret(char *ret, char const *s1, size_t l, size_t r)
{
	while (l <= r)
	{
		*ret = (char)s1[l];
		ret++;
		l++;
	}
	*ret = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	char	*ret;

	left_right_ptr(s1, set, &l, &r);
	if ((l > r) || ((l == r) && (s1[l] == '\0')))
	{
		ret = ((char *)malloc(1 * sizeof(char)));
		if (ret != NULL)
			ret[0] = '\0';
		return (ret);
	}
	ret = ((char *)malloc((r - l + 2) * sizeof(char)));
	if (ret != NULL)
		copyret(ret, s1, l, r);
	return (ret);
}
/*
#include <string.h>
#include <errno.h>
#include <stdio.h>

void	pstrtrim(char const *s1, char const *set)
{
	char	*r;

	printf("\ns (%s), set (%s)", s1, set);
	r = ft_strtrim(s1, set);
	if (r != NULL)
		printf("\ntrim (%s)\n", ft_strtrim(s1, set));
	else
		printf("\nNULL str (%s)", strerror(errno));
}

int	main(void)
{
	pstrtrim("asha; asdla;g ag;adjg gadf'jg", "asg");
	pstrtrim("aaldjuwlhga; a;lsdjasla glas;ldgj", "alj");
	pstrtrim("aaldjuwlhga; a;lsdjasla glas;ldgj", "dgalj");
	pstrtrim("aaldjuwlhga; a;lsdjasla glas;ldgj", "galdj");
	pstrtrim("", "alj");
	pstrtrim("aald", "aldj");
	pstrtrim("a", "aldj");
	pstrtrim(";", "aldj");
	pstrtrim(";", "");
	pstrtrim("abc", "cba");
	return (0);
} */
