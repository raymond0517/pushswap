/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhsu <rhsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:46:26 by rhsu              #+#    #+#             */
/*   Updated: 2023/09/30 04:48:22 by rhsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*r;

	i = 0;
	while (((char *)s)[i] != '\0')
		i++;
	r = (char *)malloc(sizeof(char) * (i + 1));
	if (r != NULL)
	{
		while (1)
		{
			r[i] = ((char *)s)[i];
			if (i == 0)
				break ;
			i--;
		}
	}
	return (r);
}
/*
#include <stdio.h>
#include <string.h>
#include <errno.h>

void	pstrdup(const char *s)
{
	char	*s1;
	char	*s2;

	s1 = ft_strdup(s);
	s2 = strdup(s);
	if (s1 == NULL)
		printf("\nft NULL (%s)", strerror(errno));
	else
	{
		printf("\nft dup (%s)", s1);
		free(s1);
	}
	if (s2 == NULL)
		printf("\nsy NULL");
	else
	{
		printf("\nsy dup (%s)", s2);
		free(s2);
	}
}

int	main(void)
{
	char *s = "I have a dream that one day on the red hills of Georgia, " \
	" the sons of former slaves and the sons of former slave owners " \
	"will be able to sit down together at the table of brotherhood. " \
	"I have a dream that one day even the state of Mississippi, " \
	"a state sweltering with the heat of injustice, "\
	" sweltering with the heat of oppression will be transformed " \
	"into an oasis of freedom and justice. "\
	"I have a dream that my four little children will one day live in a nation" \
	" where they will not be judged by the color of their skin but by the content" \
	" of their character. I have a dream today. I have a dream that one day " \
	"down in Alabama with its vicious racists, with its governor having his lips "\
	"dripping with the words of interposition and nullification, " \
	"one day right down in Alabama little Black boys and Black girls will be "\
	"able to join hands with little white boys and "\
	"white girls as sisters and brothers." \
	" I have a dream today. I have a dream that one day "\
	"every valley shall be exalted, "\
	"every hill and mountain shall be made low, "\
	"the rough places will be made plain, " \
	"and the crooked places will be made straight, and the glory of the Lord " \
	"shall be revealed, and all flesh shall see it together.";

	pstrdup("");
	pstrdup("tab\tnew line\nlast line");
	pstrdup(s);
	return (0);
} */
