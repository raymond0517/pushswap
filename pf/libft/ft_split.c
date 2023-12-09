/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:02:44 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 16:30:16 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_substr(char const *s, char c)
{
	size_t	cnt;
	int		start;

	cnt = 0;
	start = 0;
	while (*s)
	{
		if (((char)*s) != c)
			start = 1;
		else
		{
			if (start)
			{
				start = 0;
				cnt++;
			}
		}
		s++;
	}
	if (start)
		cnt++;
	return (cnt);
}

static void	fill_ret(char *ret, char *s, size_t p, size_t cnt)
{
	ret[cnt] = '\0';
	while (cnt != 0)
	{
		cnt--;
		ret[cnt] = s[p + cnt];
	}
}

/* each time get_sub is called, p will advance to next start position
	to be ready to search and fetch next substr, 
	TAKE NOTE if a particular substr malloc
    returns NULL, it will results in only this substr returns NULL, 
	and display	other substr have malloc successfully allocated, 
	which will give wrong split result, since subject requirement is not
	about this part, will let deep thought evaluate and modify when needed */

static char	*get_sub(char *s, char c, int setp)
{
	static size_t	p = 0;
	size_t			cnt;
	char			*ret;

	if (setp)
	{
		p = 0;
		return (NULL);
	}
	while ((s[p]) && (s[p] == c))
		p++;
	cnt = 0;
	while ((s[p + cnt]) && (s[p + cnt] != c))
		cnt++;
	ret = malloc(sizeof(char) * (cnt + 1));
	if (ret != NULL)
		fill_ret(ret, s, p, cnt);
	p += cnt;
	return (ret);
}

static char	**sub_malloc_fail(char **ret, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		if (ret[i])
			free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**ret;
	size_t	i;
	int		subfail;

	cnt = cnt_substr(s, c);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	subfail = 0;
	if (ret != NULL)
	{
		i = 0;
		get_sub(((char *)s), c, 1);
		while (i < cnt)
		{
			ret[i] = get_sub(((char *)s), c, 0);
			if (ret[i] == NULL)
				subfail = 1;
			i++;
		}
		ret[cnt] = NULL;
		if ((cnt) && subfail)
			ret = sub_malloc_fail(ret, cnt);
	}
	return (ret);
}
/*
#include <string.h>
#include <errno.h>
#include "stdio.h"

void	pft_split(const char *s, char c)
{
	char	**r;
	size_t	i;

	printf("\nSPLIT : s (%s), c (%c)", (char *)s, c);
	r = ft_split(s, c);
	if (r != NULL)
	{
		i = 0;
		while (r[i] != NULL)
		{
			printf("\n%lu (%s)", i, r[i]);
			free(r[i]);
			i++;
		}
		printf("\n%lu (%s)", i, r[i] == NULL ? "NULL" : "not null");
		free(r[i]);
		free(r);
	}
	else
	{
		printf("\nNULL returned (%s)", strerror(errno));
	}
	printf("\n---------");
}

int	main(void)
{
	pft_split("hello!zzzzzzzz", 'z');
	pft_split("xxxhello!", 'x');
	pft_split("hello!", ' ');
	pft_split("", ',');
	pft_split("", '\0');
	pft_split("abc", '\0');
	pft_split("kkaha;jgjjgk;lsjsdafasdfjjasdg3we4ta32t", 'a');
	pft_split(" in th  e a   fa we awlt", ' ');
	pft_split("     ", ' ');
	pft_split("a   b ", ' ');
	pft_split("ag;askgjwe252301", ' ');
	pft_split("a    b", ' ');
	pft_split("  		\n  ", ' ');
	return (0);
} */
