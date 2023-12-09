/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:29:21 by rhsu              #+#    #+#             */
/*   Updated: 2023/12/05 04:30:27 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
